/*
ex2��˫����汾
*/
#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node *pre;
};
node *head; //ͷָ��

void delete_chain(node *head, int i) {
	node *p = head->next;
	if (p->data == i) { //��һ������
		head->next = p->next;
		p->next->pre = head;
	}
	while (p->next != NULL) {
		if (p->next->data == i) { //������
			p->next = p->next->next;
			p->next->pre = p;
		}
		if (p->next == NULL) { //ɾ����û��
			break;
		}
		p = p->next;
	}
}

int main() {
	head = new node;
	head -> next = NULL;
	head->pre = NULL;
	//����
	int n;
	cin >> n;
	node *p = head;
	for (int i = 0; i < n; i++) {
		node *t = new node;
		cin >> t->data;
		t->next = p->next;
		t->pre = p;
		p->next = t;
		p = p->next;
	}
	int target;
	cin >> target;
	delete_chain(head, target);//ȥ��3
	p = head->next;
	while (p != NULL) {//���
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}