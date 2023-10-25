#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i <= 9 ; i++) {
		v.push_back(i);
	}
	v.erase(v.begin() + 5);
	v.insert(v.begin() + 2, 11);
	v.push_back(50);
	cout << v.front() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	v.clear();
	//vector<int>.swap(v);
	cout << v.size();
	return 0;
}