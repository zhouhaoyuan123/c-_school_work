#include <iostream>
using namespace std;

struct node {
	char value;
	int left, right;
} t[101];
int root = 0;
int cnt = 0;
char ch;

int buildTree(int bt) {
	cin >> ch;
	if (ch == '.') {
		bt = 0;
		return bt;
	} else {
		bt = ++cnt;
		t[bt].value = ch;
		t[bt].left = t[bt].right = 0;
		t[bt].left = buildTree(bt);
		t[bt].right = buildTree(bt);
	}
	return bt;
}

void postorder(int bt) {
	if (bt) {
		postorder(t[bt].left);
		postorder(t[bt].right);
		cout << t[bt].value << " ";
	}
}

int main() {
	root = buildTree(0);
	postorder(root);
	return 0;
}