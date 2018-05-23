#include <iostream>
#include <string>

using namespace std;

class Computer {
	int HDD;
	int RAM;
	string CPU;
	string GPU;
	int monitor;

public:
	Computer(int hdd, int ram, string cpu, string gpu, int m) {
		HDD = hdd;
		RAM = ram;
		CPU = cpu;
		GPU = gpu;
		monitor = m;
	}

	void showSpec() {
		cout << "CPU Model : " << CPU << "\n";
		cout << "GPU Model : " << GPU << "\n";
		cout << "HDD Size : " << HDD << "\n";
		cout << "RAM Size : " << RAM << "\n";
		cout << "Monitor Count : " << monitor << "\n\n";
	}
};

class ComputerBuilder {
	int HDD;
	int RAM;
	string CPU;
	string GPU;
	int monitor;

	void init() {
		HDD = 500;
		RAM = 4;
		CPU = "Intel i3 Core";
		GPU = "Nvidia 560X";
		monitor = 1;
	}

public:
	ComputerBuilder() {
		init();
	}

	ComputerBuilder& setHDD(int hdd) {
		HDD = hdd;
		return *this;
	}

	ComputerBuilder& setRAM(int ram) {
		RAM = ram;
		return *this;
	}

	ComputerBuilder& setCPU(string cpu) {
		CPU = cpu;
		return *this;
	}

	ComputerBuilder& setGPU(string gpu) {
		GPU = gpu;
		return *this;
	}

	ComputerBuilder& setMonitor(int m) {
		monitor = m;
		return *this;
	}

	Computer* build() {
		Computer *ret = new Computer(HDD, RAM, CPU, GPU, monitor);
		init();
		return ret;
	}
};

int main() {

	Computer *com;
	ComputerBuilder cb;

	com = cb.setHDD(300).setRAM(8).setCPU("Intel i7 Core").setGPU("Nvidia 1080").setMonitor(2).build();
	com->showSpec();
	delete com;
	com = cb.setRAM(16).setHDD(1000).setMonitor(5).build();
	com->showSpec();
	delete com;

	return 0;
}
