#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component {
	string name;
public:
	Component(string n) {name = n;}
	virtual void show() {}
	virtual void traversal() {}
	string getName() {
		return name;
	}
};

class File: public Component {
public:
	File(string n): Component(n) {}
	virtual void show() {
		cout << getName() << "\n";
	}
	virtual void traversal() {
		show();
	}
};

class Directory: public Component {
	vector<Component*> vec;
public:
	Directory(string n): Component(n) {}
	virtual void show() {
		cout << getName() << "\n";
	}
	void add(Component *i) {
		vec.push_back(i);
	}
	virtual void traversal() {
		show();
		for(int i = 0; i < vec.size(); i++) {
			vec[i]->traversal();
		}
	}
};

int main() {

	File f1("Harry Potter");
	File f2("Beauti Inside");
	File f3("Avengers: Infinity War");
	File f4("Algorithm Problem");
	File f5("Basic Swift");
	File f6("Advenced C++");
	Directory d1("Movie");
	Directory d2("Book");
	Directory d3("Doc");

	d1.add(&f1);
	d1.add(&f2);
	d1.add(&f3);
	d2.add(&f4);
	d2.add(&f5);
	d2.add(&f6);
	d3.add(&d1);
	d3.add(&d2);

	d3.traversal();
	cout << "\n\n";
	d1.traversal();
	cout << "\n\n";
	d2.traversal();

	return 0;
}
