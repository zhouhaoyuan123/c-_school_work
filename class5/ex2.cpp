#include <iostream>
using namespace std;
int a[10001];
int front, rear;
int x, maxl = 10;

void push(int x) {
	if (rear < maxl) {
		a[++rear] = x;
	}
}

void pop() {
	if (front != rear) {
		front++;
	}
}

int len() {
	return rear - front;
}

int main() {

	return 0;
}