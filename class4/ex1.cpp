#include <iostream>
using namespace std;
int s[10001], n = 10, top = 0;

void push(int x) {
	if (top < n) {
		top++;
		s[top] = x;
	}
}

bool empty() {
	if (top <= 0) {
		return true;
	}
	return false;
}

void pop() {
	if (top > 0) {
		top--;
	}
}

void clear() {
	top = 0;
}

int show() {
	return s[top];
}

int main() {
	//int top = 0;
	int x;
	//cin >> n;
//	while (cin >> x && x != -1) {
//		if (top >= n)
//			break;
//		s[top] = x;
//		top++;
//	}
	for (int i = 1; i <= 5; i++) {
		push(i);
	}
	cout << show() << endl;
	pop();
	pop();
	cout << show() << endl;
	if (!empty()) {
		while (!empty()) {
			cout << show() << " ";
			pop();
		}
	}
	return 0;
}