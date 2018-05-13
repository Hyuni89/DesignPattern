#include <iostream>

using namespace std;

class Food {
public:
	virtual void make() = 0;
	virtual ~Food() {}
};

class Pizza: public Food {
public:
	virtual void make() {
		cout << "make Pizza base\n";
		cout << "put topping\n";
		cout << "bake in oven\n";
		cout << "Done!! Enjoy Pizza\n\n";
	}
};

class Pasta: public Food {
public:
	virtual void make() {
		cout << "make Noodle\n";
		cout << "make Source\n";
		cout << "mix them\n";
		cout << "Done!! Enjoy Pasta\n\n";
	}
};

class Command {
	Food *food;
public:
	Command() {
		food = nullptr;
	}
	~Command() {
		if(food != nullptr) delete food;
	}
	void makeOrder(Food *food) {
		this->food = food;
	}
	void make() {
		if(food == nullptr) {
			cout << "Cheif: No Food Ordered. What happen??\n\n";
			return;
		}
		food->make();
	}
};

class Cheif {
	Command *command;
	public:
	Cheif() {
		command = nullptr;
	}
	void getCommand(Command *c) {
		if(command != nullptr) delete command;
		command = c;

		command->make();

		delete command;
		command = nullptr;
	}
};

class Waiter {
	Command *command;
	Cheif cf;
public:
	Waiter() {
		command = nullptr;
	}
	void setCommand(Command *c) {
		if(c == nullptr) {
			cout << "Waiter: make Order Please\n\n";
			return;
		}
		command = c;
		cf.getCommand(command);
	}
};

class Client {
public:
	Command* chooseMenu(string s) {
		Command *ret = new Command();
		if(s == "Pizza" || s == "pizza") {
			ret->makeOrder(new Pizza());
		} else if(s == "Pasta" || s == "pasta") {
			ret->makeOrder(new Pasta());
		}

		return ret;
	}
};

int main() {

	Client client;
	Waiter waiter;

	waiter.setCommand(client.chooseMenu("Pizza"));
	waiter.setCommand(client.chooseMenu("??"));
	waiter.setCommand(client.chooseMenu("pasta"));

	return 0;
}
