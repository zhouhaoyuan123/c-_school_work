#include <iostream>
#include <string>
using namespace std;

struct node {
	char data;
	int l, r;
} tree[1005];
int cnt = 0;

void transform_tree(int mode, int start, string s, string s2) {
	cout << start << endl;
	if (cnt == 0) {
		tree[cnt].data = s[0];
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		string res1 = s.substr(1, (s2.substr(0, s2.find(s[0]))).size());
		string res2 = s2.substr(0, s2.find(s[0]));
		string res3 = s.substr(res1.size() + 1);
		string res4 = s2.substr(s2.find(s[0]) + 1);
		int tmp = cnt - 1;
		transform_tree(0, cnt - 1, res1, res2);
		transform_tree(1, tmp, res3, res4);
		return;
	}
	if (s.size() == 1) {
		tree[cnt].data = s[0];
		if (mode == 0) {
			tree[start].l = cnt;
		} else {
			tree[start].r = cnt;
		}
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		return;
	}
	if (mode == 0) {
		tree[start].l = cnt;
		tree[cnt].data = s[0];
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		string res1 = s.substr(1, (s2.substr(0, s2.find(s[0]))).size());
		string res2 = s2.substr(0, s2.find(s[0]));
		string res3 = s.substr(res1.size() + 1);
		string res4 = s2.substr(s2.find(s[0]) + 1);
		int tmp = cnt - 1;
		transform_tree(0, cnt - 1, res1, res2);
		transform_tree(1, tmp , res3, res4);
	} else {
		tree[start].r = cnt;
		tree[cnt].data = s[0];
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		string res1 = s.substr(1, (s2.substr(0, s2.find(s[0]))).size());
		string res2 = s2.substr(0, s2.find(s[0]));
		string res3 = s.substr(res1.size() + 1);
		string res4 = s2.substr(s2.find(s[0]) + 1);
		int tmp = cnt - 1;
		transform_tree(0, cnt - 1, res1, res2);
		transform_tree(1, tmp, res3, res4);
	}
}

void print(int bt) {
	if (bt != -1) {
		print(tree[bt].l);
		print(tree[bt].r);
		cout << tree[bt].data << " ";
	}
}

int main() {
	string s, s1;
	cin >> s >> s1;
	transform_tree(0, 0, s, s1);
	print(0);
	return 0;
}
