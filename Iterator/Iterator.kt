interface Iterator {
	fun hasNext(): Boolean
	fun next(): Any
}

interface Aggregate {
	fun iterator(): Iterator
}

class Book(name: String) {
	private var name: String
	init {
		this.name = name
	}
	fun getName(): String {
		return this.name
	}
}

class BookShelfIterator(bs: BookShelf): Iterator {
	private var bookshelf: BookShelf
	private var index: Int
	init {
		bookshelf = bs
		index = 0
	}
	override fun hasNext(): Boolean {
		if(index < bookshelf.getSize()) {
			return true
		} else {
			return false
		}
	}
	override fun next(): Any {
		val ret = bookshelf.index(index)
		index++
		return ret
	}
}

class BookShelf: Aggregate {
	private var book: MutableList<Book>
	private var size: Int
	init {
		book = mutableListOf<Book>()
		size = 0
	}
	fun append(b: Book) {
		book.add(b)
		size++;
	}
	fun index(i: Int): Book {
		return book[i]
	}
	fun getSize(): Int {
		return size
	}
	override fun iterator(): Iterator {
		return BookShelfIterator(this)
	}
}

fun main(args: Array<String>) {
	val bs = BookShelf()
	bs.append(Book("Bible"))
	bs.append(Book("Cook Book"))
	bs.append(Book("Data Structure"))
	bs.append(Book("Algorithm Problem"))
	bs.append(Book("Machine Learning"))

	val iter = bs.iterator()
	while(iter.hasNext()) {
		val b = iter.next() as Book
		println(b.getName())
	}
}
