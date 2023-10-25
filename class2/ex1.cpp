#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};
Node *head = new Node;

int main() {
	int n;
	cin >> n;
	Node *t = new Node;
	t->data = 1;
	t->next = NULL;
	head->next = t;
	for (int i = 0; i < n; i++) {
		int op;//模式
		cin >> op;
		Node *p = head->next;
		if (op == 1) {
			int x, y;
			cin >> x >> y;
			Node *t2 = new Node;
			t2->data = y;
			//循环
			while (p != NULL) {
				if (p->data == x) {
					t2->next = p->next;
					p->next = t2;
					break;
				}
				p = p->next;
			}
		} else if (op == 2) {
			int x;
			cin >> x;
			while (p != NULL) {
				if (p->data == x) {
					if (p->next == NULL) {
						cout << 0 << endl;
					} else {
						cout << p->next->data << endl;
					}
					break;
				}
				p = p->next;
			}
			//循环+输出
		} else {
			int x;
			cin >> x;
			while (p != NULL) {
				if (p->data == x) {
					if (p->next == NULL) {
						break;
					} else {
						p->next = p->next->next;
					}
					break;
				}
				p = p->next;
			}
			//循环+if()
		}
	}
	return 0;
}