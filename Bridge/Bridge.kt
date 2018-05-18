interface Weapon {
	public fun use()
}

class Gun: Weapon {
	override public fun use() {
		println("Shooting Gun")
	}
}

class Fire: Weapon {
	override public fun use() {
		println("Fire fire")
	}
}

class Bomb: Weapon {
	override public fun use() {
		println("Throw Bomb")
	}
}

abstract class Object(w: Weapon) {
	var weapon: Weapon?
	abstract public fun use()
	init {
		weapon = w
	}
}

class Marin(w: Weapon): Object(w) {
	override public fun use() {
		print("Marin: ")
		weapon?.use()
	}
}

class Ghost(w: Weapon): Object(w) {
	override public fun use() {
		print("Ghost: ")
		weapon?.use()
	}
}

fun main(args: Array<String>) {
	val gun = Gun()
	val fire = Fire()
	val bomb = Bomb()

	val m1 = Marin(gun)
	m1.use()
	val m2 = Marin(fire)
	m2.use()
	val m3 = Marin(bomb)
	m3.use()
	val g1 = Ghost(gun)
	g1.use()
	val g2 = Ghost(fire)
	g2.use()
	val g3 = Ghost(bomb)
	g3.use()
}
