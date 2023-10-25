#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

void chain_insert(node *head, int i, int x) {
	node *p = head->next; //指针
	int cnt = 0;
	while (true) {
		if (p == NULL) {
			node *t = new node;
			t->data = i;
			t->next = NULL;
			node *t2 = new node;
			t2->data = x;
			t2->next = NULL;
			t->next = t2;
			head->next = t;
			return;
		}
		if (p->data == i) {
			node *t = new node;
			t->data = x;
			t->next = p->next;
			p->next = t;
			return;
		}
		p = p->next;
		cnt++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	node *head = new node;
	head->next = NULL;
	//初始化链表（输入，插入）
	for (int i = 0; i < n; i++) {
		int i2, j;
		cin >> i2 >> j;
		if (j == 0) {
			continue;
		}
		chain_insert(head, i2, j);
	}
	//插入
	for (int i = 0; i < m; i++) {
		int i2, j;
		cin >> i2 >> j;
		chain_insert(head, i2, j);
	}
	node *p = head->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
	return 0;
}