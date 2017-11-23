protocol IProduct {
    var name: String {get}
    func A(a: String)
    func B(b: String)
    func C(c: String)
}

class AProduct: IProduct {
    var name: String
    init(name: String) {
        self.name = name
    }
    func A(a: String) {
        print(self.name, a)
    }
    func B(b: String) {
        print(self.name, b)
    }
    func C(c: String) {
        print(self.name, c)
    }
}

class BProduct: IProduct {
    var name: String
    init(name: String) {
        self.name = name
    }
    func A(a: String) {
        print(self.name, a)
    }
    func B(b: String) {
        print(self.name, b)
    }
    func C(c: String) {
        print(self.name, c)
    }
}

class Factory {
    var product: IProduct?
    init() {
        product = nil
    }
    func create(which: Character, name: String) -> IProduct {
        switch(which) {
            case "a", "A": self.product = AProduct(name: name)
            case "b", "B": self.product = BProduct(name: name)
            default: break
        }
        return self.product!
    }
}

let fac = Factory()
let elementA = fac.create(which: "A", name: "elementA")
let elementB = fac.create(which: "b", name: "elementB")
elementA.A(a: "func A")
elementA.B(b: "func B")
elementA.C(c: "func C")
elementB.A(a: "func A")
elementB.B(b: "func B")
elementB.C(c: "func C")