#include <cstdio>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <unistd.h>

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
    SubMachine(bool *flag) {
        num=0;
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
            printf("[%lu]thread num is [%d]\n", pthread_self(), num);
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
    void del(int index) {
        Element *get=list[index];
        pthread_t *getThread=thList[index];
        list.erase(list.begin()+index);
        thList.erase(thList.begin()+index);
        pthread_cancel(*getThread);
        delete getThread;
        delete get;
    }
public:
    void add() {
        bool *f=new bool(false);
        flag.push_back(f);
        Element *in=new SubMachine(f);
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
        for(int i=0; i<list.size(); i++) {
            if(*flag[i]) {
                delete flag[i];
                flag.erase(flag.begin()+i);
                list.erase(list.begin()+i);
                delete thList[i];
                thList.erase(thList.begin()+i);
                flag.erase(flag.begin()+i);
                i--;
            }
        }
    }
    void cut(int limit) {
        for(int i=0; i<list.size(); i++) {
            int num=list[i]->posNum();
            if(num<limit) {
                printf("[%d] index is less than limit[limit>%d]. Delete it\n", i, num);
                del(i);
            }
        }
    }
    int getSize() {
        return list.size();
    }
    PrimeOne() {}
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
    }
    ~PrimeOne() {
        for(int i=0; i<list.size(); i++) {
            del(i);
        }
    }
};

int main() {
    int init=10;
    PrimeOne p(init);
    printf("Element Start Size is [%d]\n", init);
    printf("Main Thread[%lu]\n", pthread_self());
    for(int i=0; i<5; i++) {
        sleep(60);
        printf("Limit [%d]\n", i*10);
        p.limitUpdate(i*10);
        printf("Element Size is [%d]\n", p.getSize());
    }
    return 0;
}