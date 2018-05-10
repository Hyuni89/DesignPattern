class Glove {
	var name: String
	init() {
		name = "Glove"
	}
}

class PlainGlove: Glove {
	override init() {
		super.init()
		self.name = "Plain Glove"
	}
}

class HalfGlove: Glove {
	override init() {
		super.init()
		self.name = "Half Glove"
	}
}

class LongGlove: Glove {
	override init() {
		super.init()
		self.name = "Long Glove"
	}
}

class Factory {
	func getMaterial() {
		print("Normal Material", terminator: " ")
	}
	
	func setDesign() {
		print("Normal Design", terminator: " ")
	}

	func doProcess() {
		print("Normal Process", terminator: " ")
	}

	func make(menu: String) -> Glove? {
		getMaterial()
		setDesign()
		doProcess()

		switch menu {
			case "Plain": return PlainGlove()
			case "Long": return LongGlove()
			case "Half": return HalfGlove()
			default: return nil
		}
	}
}

class FranchFactory: Factory {
	override func getMaterial() {
		print("Silk", terminator: " ")
	}

	override func setDesign() {
		print("French", terminator: " ")
	}

	func addJewelry() {
		print("Diamond", terminator: " ")
	}

	override func doProcess() {
		print("HighQ", terminator: " ")
	}

	override func make(menu: String) -> Glove? {
		getMaterial()
		setDesign()
		addJewelry()
		doProcess()

		switch menu {
			case "Plain": return PlainGlove()
			case "Long": return LongGlove()
			case "Half": return HalfGlove()
			default: return nil
		}
	}
}

class KoreanFactory: Factory {
	override func getMaterial() {
		print("Leather", terminator: " ")
	}

	override func setDesign() {
		print("Korean", terminator: " ")
	}

	override func doProcess() {
		print("FastM", terminator: " ")
	}
	
	override func make(menu: String) -> Glove? {
		getMaterial()
		setDesign()
		doProcess()

		switch menu {
			case "Plain": return PlainGlove()
			case "Long": return LongGlove()
			case "Half": return HalfGlove()
			default: return nil
		}
	}
}

class GloveShop {
	func order(fac: Factory, menu: String) -> Glove? {
		return fac.make(menu: menu)
	}
}

let gs = GloveShop()
let g1 = gs.order(fac: FranchFactory(), menu: "Long")
print(g1!.name)
let g2 = gs.order(fac: KoreanFactory(), menu: "Plain")
print(g2!.name)
let g3 = gs.order(fac: Factory(), menu: "Half")
print(g3!.name)
