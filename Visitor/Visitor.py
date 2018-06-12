class CarVisitor:
    def visit(self, part):
        pass

class CarPart:
    def accept(self, visitor):
        pass
    def isBroken(self):
        pass

class Engine(CarPart):
    def __init__(self, name, broken):
        self.name = name
        self.broken = broken
    def isBroken(self):
        return self.broken
    def accept(self, visitor):
        visitor.visit(self)

class Handle(CarPart):
    def __init__(self, name, broken):
        self.name = name
        self.broken = broken
    def isBroken(self):
        return self.broken
    def accept(self, visitor):
        visitor.visit(self)

class Wheel(CarPart):
    def __init__(self, name, broken):
        self.name = name
        self.broken = broken
    def isBroken(self):
        return self.broken
    def accept(self, visitor):
        visitor.visit(self)

class Car(CarPart):
    def __init__(self, name):
        self.name = name
        self.part = []
    def addPart(self, part):
        self.part.append(part)
    def accept(self, visitor):
        for i in self.part:
            i.accept(visitor)
        visitor.visit(self)
    def isBroken(self):
        ret = False
        for i in self.part:
            ret = i.isBroken()
            if ret is True:
                break
        return ret

class Inspector(CarVisitor):
    part = []
    def visit(self, part):
        if part is Car:
            for i in part.part:
                i.accept(self)
        else:
            if part.isBroken():
                print("Found Broken Part %s" % part.name)

ins = Inspector()

car = Car("Morning")
car.addPart(Engine("Engine", False))
car.addPart(Wheel("Wheel", True))
car.addPart(Handle("Handle", True))
car.accept(ins)

car = Car("Niro")
car.addPart(Engine("Engine", True))
car.addPart(Wheel("Wheel", False))
car.addPart(Handle("Handle", False))
car.accept(ins)
