#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> list1;
	list<int>::iterator it;
	list<int>::reverse_iterator ir;
	list1.push_back(1);
	list1.push_front(5);
	for (it = list1.begin(); it != list1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	for (ir = list1.rbegin(); ir != list1.rend(); ir++) {
		cout << *ir << " ";
	}
	cout << endl;
	list1.pop_back();
	list1.pop_front();
	for (it = list1.begin(); it != list1.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}