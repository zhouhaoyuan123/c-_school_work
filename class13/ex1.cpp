#include <iostream>
using namespace std;

struct node {
	int data;
	int left;
	int right;
} tree[100005];
int cnt = 0;
int root = 0;

void build (int n, int start) {
	if (cnt == 0) {
		tree[root].data = n;
		tree[root].right = -1;
		tree[root].left = -1;
		++cnt;
		return ;
	}
	if (tree[start].data == n) {
		return ;
	}
	cout << tree[start].data << endl;
	if (tree[start].data < n) {
		if (tree[start].right == -1) {
			tree[start].right = cnt;
			tree[cnt].data = n;
			tree[cnt].left = -1;
			tree[cnt].right = -1;
			++cnt;
			return;
		}
		build(n, tree[start].right);
	} else {
		if (tree[start].left == -1) {
			tree[start].left = cnt;
			tree[cnt].data = n;
			tree[cnt].left = -1;
			tree[cnt].right = -1;
			++cnt;
			return;
		}
		build(n, tree[start].left);
	}
}

bool search (int n, int start) {
	if (tree[start].data == n) {
		return true;
	}
	if (tree[start].data < n) {
		if (tree[start].right == -1) {
			return false;
		}
		return search(n, tree[start].right);
	} else {
		if (tree[start].left == -1) {
			return false;
		}
		return search(n, tree[start].left);
	}
}

void postorder(int bt) {
	if (bt != -1) {
		postorder(tree[bt].left);
		cout << tree[bt].data << " ";
		postorder(tree[bt].right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		build(tmp, root);
	}
	postorder(root);
	cout << endl;
	cout << search(5, root);
	return 0;
}