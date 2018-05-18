protocol Quackable {
	func quack()
}

class MallardDuck: Quackable {
	func quack() {
		print("Quack")
	}
}

class RedheadDuck: Quackable {
	func quack() {
		print("quack")
	}
}

class RubberDuck: Quackable {
	func quack() {
		print("Squeak")
	}
}

class DuckCall: Quackable {
	func quack() {
		print("Kwak")
	}
}

class Goose {
	func honk() {
		print("Honk")
	}
}

class Adapter: Quackable {
	var goose: Goose?
	init(g: Goose) {
		goose = g
	}
	func quack() {
		guard let g = goose else {
			print("Error:: Can't Quack Goose")
			return
		}
		g.honk()
	}
}

class QuackCounter: Quackable {
	static var cnt: Int = 0
	var qu: Quackable?
	init(q: Quackable) {
		qu = q
	}
	func quack() {
		guard let q = qu else {
			print("Error::")
			return
		}
		QuackCounter.cnt += 1
		q.quack()
	}
}

protocol AbstractDuckFactory {
	func createMallardDuck() -> Quackable
	func createRedheadDuck() -> Quackable
	func createDuckCall() -> Quackable
	func createRubberDuck() -> Quackable
}

class CountingDuckFactory: AbstractDuckFactory {
	func createMallardDuck() -> Quackable {
		return QuackCounter(q: MallardDuck())
	}
	func createRedheadDuck() -> Quackable {
		return QuackCounter(q: RedheadDuck())
	}
	func createDuckCall() -> Quackable {
		return QuackCounter(q: DuckCall())
	}
	func createRubberDuck() -> Quackable {
		return QuackCounter(q: RubberDuck())
	}
}

let factory = CountingDuckFactory()
let mallard = factory.createMallardDuck()
let redhead = factory.createRedheadDuck()
let call = factory.createDuckCall()
let rubber = factory.createRubberDuck()
let goose = Adapter(g: Goose())

mallard.quack()
redhead.quack()
call.quack()
rubber.quack()
goose.quack()

print("Ducks Quack \(QuackCounter.cnt) times")
