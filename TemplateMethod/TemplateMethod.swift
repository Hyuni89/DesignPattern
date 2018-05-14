class HotDrink {
	func makeDrink() {
		boilWater()
		whichDrink()
		onCup()
		hook()
	}
	func boilWater() {
		print("boil water")
	}
	func whichDrink() {}
	func onCup() {
		print("put cup")
	}
	func hook() {}
}

class Coffee: HotDrink {
	override func whichDrink() {
		print("put coffee on hot water")
	}
	override func hook() {
		print("add prim")
	}
}

class Tea: HotDrink {
	override func whichDrink() {
		print("put tea back on hot water")
	}
}

var drink = Coffee() as HotDrink
drink.makeDrink()
drink = Tea() as HotDrink
drink.makeDrink()
