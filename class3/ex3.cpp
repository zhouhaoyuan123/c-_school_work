#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node *prev;
};

int main() {
	node *head = new node;
	head->prev = NULL;//��ʼ��
	//����
	string tmp;
	getline(cin, tmp);
	node *p = head;
	while (tmp != "end") { //����(getline)
		node *t = new node;
		t->data = tmp;
		t->prev = p;
		p = t;
		getline(cin, tmp);
	}
	while (p != head) {//���
		cout << p->data << endl;
		p = p->prev;
	}
	return 0;
}