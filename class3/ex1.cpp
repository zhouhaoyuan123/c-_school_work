#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};
node *head;

int main() {
	head = new node;
	head->next = head;//��
	head->data = -1;
	int n, m;
	cin >> n >> m;
	node *p = head->next;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {//����
		node *t = new node;
		t->data = i;
		t->next = p->next;
		p->next = t;
		p = p->next;
	}
	p = head->next;
	while (head->next != head) {//ֱ��Ϊ��
		cnt++;
		if (cnt + 1 == n) {//����
			cnt = 0;
			if (p->next->data == -1) {
				p = p->next;
				cout << p -> next->data << " ";
				p->next = p->next->next;
			} else {
				cout << p -> next->data << " ";
				p->next = p->next->next;
			}
			//continue;
		}
		p = p->next;
		if (p ->data == -1) {
			p = p->next;
		}
	}
	return 0;
}