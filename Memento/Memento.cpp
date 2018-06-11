#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Memento {
	vector<Point> prev;
	vector<Point> last;
public:
	void put(int x, int y) {
		prev.push_back(Point(x, y));
		last.clear();
		show();
	}
	void undo() {
		if(prev.size() > 0) {
			last.push_back(prev.back());
			prev.erase(prev.end());
		} else {
			printf("No history\n");
		}
		show();
	}
	void redo() {
		if(last.size() > 0) {
			prev.push_back(last.back());
			last.erase(last.end());
		} else {
			printf("No redo\n");
		}
		show();
	}
	void show() {
		char map[19][19];
		memset(map, '.', sizeof(map));

		for(int i = 0; i < prev.size(); i++) {
			if(i % 2) map[prev[i].y][prev[i].x] = '@';
			else map[prev[i].y][prev[i].x] = '#';
		}

		for(int i = 0; i < 19; i++) {
			for(int j = 0; j < 19; j++) {
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
};

int main() {
	Memento m;
	m.put(4, 4);
	m.put(2, 1);
	m.put(18, 6);
	m.put(4, 18);
	m.undo();
	m.undo();
	m.redo();
	m.put(12, 12);
	m.redo();

	return 0;
}
