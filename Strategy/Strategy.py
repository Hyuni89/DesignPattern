import sys

class IProcess:
    def __init__(self):
        pass
    def load(self, path):
        pass
    def show(self):
        pass

class ProcessKO(IProcess):
    first=["ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
    second=["ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ"]
    third=["", "ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
    def __init__(self):
        pass
    def load(self, path):
        ret=[]
        with open(path) as fin:
            for line in fin.readlines():
                ret.append(self.sep(line.strip()))
        return ret
    def show(self, word):
        for i in word:
            print(self.comb(i), end=' ')
        print()
    def sep(self, word):
        ret=[]
        for i in word:
            fc=self.first[int(((((ord(i)-0xAC00)-(ord(i)-0xAC00)%28))/28)/21)]
            sc=self.second[int(((((ord(i)-0xAC00)-(ord(i)-0xAC00)%28))/28)%21)]
            tc=self.third[int((ord(i)-0xAC00)%28)]
            ret.append(fc)
            ret.append(sc)
            ret.append(tc)
        return ret
    def comb(self, word):
        ret=""
        for i in range(0, len(word), 3):
            fi=self.getIndex(self.first, word[i])
            si=self.getIndex(self.second, word[i+1])
            ti=self.getIndex(self.third, word[i+2])
            ret+=chr(0xAC00+28*21*fi+28*si+ti)
        return ret
    def getIndex(self, arr, c):
        for i in range(len(arr)):
            if arr[i]==c:
                return i
        return -1


class ProcessEN(IProcess):
    def __init__(self):
        pass
    def load(self, path):
        ret=[]
        with open(path) as fin:
            for line in fin.readlines():
                ret.append(line.strip())
        return ret
    def show(self, word):
        for i in word:
            print(i, end=' ')
        print()

class IPreload:
    word=[]
    module=None
    def __init__(self):
        pass
    def load(self):
        pass
    def inMem(self):
        for i in self.word:
            print(i, end=' ')
        print()
    def show(self):
        pass

class Preload(IPreload):
    def __init__(self, m):
        self.module=m
    def load(self, path):
        self.word=self.module.load(path)
    def show(self):
        self.module.show(self.word)

ko=Preload(ProcessKO())
en=Preload(ProcessEN())
en.load("en.txt")
en.inMem()
en.show()
ko.load("ko.txt")
ko.inMem()
ko.show()
