#include <iostream>
#include <string>
char s[260];
int n = 256;
int top = 0;
using namespace std;

void push(char x) {
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

char show() {
	return s[top];
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; s[i] != '@'; i++) {
		if (s[i] == '(') {
			push(s[i]);
		}
		if (s[i] == ')') {
			pop();
		}
	}
	if (!empty()) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}