protocol Expression {
	func interpret(variable: [String:Expression]) -> Int
}

class Number: Expression {
	var number: Int
	init(num: Int) {
		number = num
	}
	func interpret(variable: [String:Expression]) -> Int {
		return number
	}
}

class Plus: Expression {
	var left: Expression
	var right: Expression
	init(l: Expression, r: Expression) {
		left = l
		right = r
	}
	func interpret(variable: [String:Expression]) -> Int {
		return left.interpret(variable: variable) + right.interpret(variable: variable)
	}
}

class Minus: Expression {
	var left: Expression
	var right: Expression
	init(l: Expression, r: Expression) {
		left = l
		right = r
	}
	func interpret(variable: [String:Expression]) -> Int {
		return left.interpret(variable: variable) - right.interpret(variable: variable)
	}
}

class Variable: Expression {
	var name: String
	init(name: String) {
		self.name = name
	}
	func interpret(variable: [String:Expression]) -> Int {
		return variable[name]!.interpret(variable: variable)
	}
}

class Evaluator: Expression {
	var syntaxTree: Expression
	init(exp: String) {
		var st = [Expression]()
		for token in exp.split(separator: " ") {
			if token == "+" {
				let sub = Plus(l: st.removeLast(), r: st.removeLast())
				st.append(sub)
			} else if token == "-" {
				let r = st.removeLast()
				let l = st.removeLast()
				let sub = Minus(l: l, r: r)
				st.append(sub)
			} else {
				st.append(Variable(name: String(token)))
			}
		}
		syntaxTree = st.removeLast()
	}
	func interpret(variable: [String:Expression]) -> Int {
		return syntaxTree.interpret(variable: variable)
	}
}

let exp = "w x z - +";
let sentence = Evaluator(exp: exp)
var variable = [String:Expression]()
variable["w"] = Number(num: 5)
variable["x"] = Number(num: 10)
variable["z"] = Number(num: 42)
let res = sentence.interpret(variable: variable)

print(res)
