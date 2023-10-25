#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct person {
	string name;
	int n;
};

int main() {
	int x, y = 0;
	string s;
	cin >> x;
	int flag = 0;
	vector<person> vec;
	while (cin >> s) {
		if (s == "tingtingting") {
			y -= vec[vec.size() - 1].n;
			if (vec[vec.size() - 1].name == "kaomianjin") {
				flag = 2;
				break;
			}
			continue;
		}
		if (vec.size() > 0) {
			if (vec[vec.size() - 1].name == "kaomianjin") {
				flag = 1;
				break;
			}
		}
		if (y > x) {
			break;
		}
		person p;
		p.name = s;
		cin >> p.n;
		vec.push_back(p);
		y += p.n;
	}
	if (vec[vec.size() - 1].name == "kaomianjin" && flag == 0) {
		flag = 1;
	}
	if (flag == 0) {
		cout << "Unfortunately.";
	} else if (flag == 1) {
		cout << "Congratulations!";
	} else {
		cout << "Hahaha.";
	}
	return 0;
}