#include <cstdio>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>

using namespace std;

class Element {
public:
    virtual void* run()=0;
    virtual int posNum()=0;
    virtual void update(int)=0;
    virtual ~Element() {};
};

class SubMachine: public Element {
    int num;
    int limit;
    bool *flag;
public:
    SubMachine(bool *flag, int initNum=0) {
        num=initNum;
        limit=0x80000000;
        this->flag=flag;
    }
    ~SubMachine() {
        printf("Delete [%lu][%d]\n", pthread_self(), num);
    }
    virtual void* run() {
        while(true) {
            int sleepTime=(rand()%10)+1;
            sleep(sleepTime);
            int inc=(rand()%101)-50;
            num+=inc;
            if(num<limit) {
                *flag=true;
                delete this;
                return (void*)0;
            }
            printf("[%lu]thread num is [%4d]\n", pthread_self(), num);
        }
    }
    virtual int posNum() {return num;}
    virtual void update(int l) {limit=l;}
    static void* runHelper(void *element) {
        return ((SubMachine*)element)->run();
    }
};

class PrimeOne {
    vector<Element*> list;
    vector<pthread_t*> thList;
    vector<bool*> flag;
    pthread_t watchThread;
    static int getAvailList(vector<bool*> *flag) {
        int ret=0;
        for(int i=0; i<flag->size(); i++) {
            if(!(*flag->at(i))) ret++;
        }
        return ret;
    }
public:
    static void* watching(void *arg) {
        int availSize=getAvailList(static_cast<vector<bool*>* >(arg));
        while(true) {
            sleep(0.5);
            int posSize=getAvailList(static_cast<vector<bool*>* >(arg));
            if(posSize==1) {
                availSize=posSize;
                printf("Element Size [%d]\n", availSize);
                break;
            } else if(availSize!=posSize) {
                availSize=posSize;
                printf("Element Size [%d]\n", availSize);
            }
        }
    }
    void stop() {
        for(int i=0; i<list.size(); i++) {
            pthread_cancel(*thList[i]);
        }
    }
    void add(int initNum) {
        bool *f=new bool(false);
        flag.push_back(f);
        Element *in=new SubMachine(f, initNum);
        pthread_t *tmpThread=new pthread_t;
        pthread_create(tmpThread, NULL, SubMachine::runHelper, in);
        list.push_back(in);
        thList.push_back(tmpThread);
    }
    void limitUpdate(int limit) {
        for(int i=0; i<list.size(); i++) {
            if(!(*flag[i])) {
                list[i]->update(limit);
            }
        }
    }
    PrimeOne() {
        pthread_create(&watchThread, NULL, PrimeOne::watching, &flag);
    }
    PrimeOne(int n) {
        for(int i=0; i<n; i++) {
            bool *f=new bool(false);
            flag.push_back(f);
            Element *tmp=new SubMachine(f);
            pthread_t *tmpThread=new pthread_t;
            pthread_create(tmpThread, NULL, SubMachine::runHelper, tmp);
            list.push_back(tmp);
            thList.push_back(tmpThread);
        }
        pthread_create(&watchThread, NULL, PrimeOne::watching, &flag);
    }
    ~PrimeOne() {
        pthread_cancel(watchThread);
        int lastOne=0x80000000;
        for(int i=0; i<list.size(); i++) {
            if(!(*flag[i])) {
                lastOne=max(lastOne, list[i]->posNum());
                delete list[i];
            }
            delete thList[i];
            delete flag[i];
        }
        printf("LastOne Number[%d]\n", lastOne);
    }
};

int main() {
    int init=10;
    PrimeOne p(init);
    printf("Element Start Size is [%d]\n", init);
    printf("Main Thread[%lu]\n", pthread_self());
    for(int i=0; i<5; i++) {
        if(i%2) p.add(i*20);
        sleep(60);
        printf("Limit [%d]\n", i*10);
        p.limitUpdate(i*10);
    }
    p.stop();
    return 0;
}
