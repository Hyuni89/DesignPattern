class ControlTower {
	private var isUse: Boolean = false
	@Synchronized public fun getPermission(): Boolean {
		if(isUse) {
			return false
		} else {
			isUse = true
			return true
		}
	}
	public fun land(airplane: Airplane) {
		val seq = airplane.getSeq()
		println("$seq + Airplane Landing Start")
		Thread.sleep(50)
		println("$seq + Airplane Landing End")
		isUse = false;
	}
}

class Airplane(tower: ControlTower, seq: Int): Thread()  {
	private var tower: ControlTower
	private var seq: Int
	init {
		this.tower = tower
		this.seq = seq
	}
	public fun getSeq(): Int {
		return seq
	}
	override fun run() {
		try {
			while(!tower.getPermission()) {
				Thread.sleep(10)
			}
			tower.land(this)
		} catch(e: InterruptedException) {
			e.printStackTrace()
		}
	}
}

fun main(args: Array<String>) {
	val tower = ControlTower()
	var airplane = List<Airplane>(10, {i -> Airplane(tower, i)})
	for(i in airplane) {
		i.start()
	}
}
