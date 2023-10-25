/*
ex2的双链表版本
*/
#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node *pre;
};
node *head; //头指针

void delete_chain(node *head, int i) {
	node *p = head->next;
	if (p->data == i) { //第一个就是
		head->next = p->next;
		p->next->pre = head;
	}
	while (p->next != NULL) {
		if (p->next->data == i) { //后面是
			p->next = p->next->next;
			p->next->pre = p;
		}
		if (p->next == NULL) { //删除后没了
			break;
		}
		p = p->next;
	}
}

int main() {
	head = new node;
	head -> next = NULL;
	head->pre = NULL;
	//输入
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
	delete_chain(head, target);//去掉3
	p = head->next;
	while (p != NULL) {//输出
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}