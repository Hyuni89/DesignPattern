class Singleton private constructor() {
	var num: Int

	init {
		num = 0
	}

	fun setNumber(n: Int) {
		num = n
	}

	fun getNumber(): Int {
		return num
	}

	companion object {
		private val mInstance: Singleton = Singleton()

		@Synchronized
		fun getInstance(): Singleton {
			return mInstance
		}
	}
}

fun main(args: Array<String>) {
	val single = Singleton.getInstance()
	println(single.getNumber())
	single.setNumber(100)

	val other = Singleton.getInstance()
	println(other.getNumber())
	other.setNumber(-100)

	val another = Singleton.getInstance()
	println(another.getNumber())
	another.setNumber(3)
	println(another.getNumber())
}
