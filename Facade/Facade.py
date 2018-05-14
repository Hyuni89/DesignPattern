class CPU:
    def freeze(self):
        print("CPU freeze")
    def jump(self, addr):
        print("CPU jump[%d]" % addr)
    def execute(self):
        print("CPU execute")

class Memory:
    def load(self, addr):
        print("Mem load[%d]" % addr)
    def reg(self):
        print("Mem reg")

class HardDrive:
    def read(self, addr):
        print("HDD read[%d]" % addr)
    def write(self):
        print("HDD write")

class Computer:
    def __init__(self):
        self.cpu = CPU()
        self.mem = Memory()
        self.hdd = HardDrive()
    def boot(self):
        self.cpu.freeze()
        self.hdd.read(0x42)
        self.mem.reg()
        self.cpu.jump(0x9f)
        self.mem.load(0xf8377f8)
        self.hdd.write()
        self.cpu.execute()

com = Computer()
com.boot()
