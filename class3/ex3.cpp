#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node *prev;
};

int main() {
	node *head = new node;
	head->prev = NULL;//初始化
	//输入
	string tmp;
	getline(cin, tmp);
	node *p = head;
	while (tmp != "end") { //输入(getline)
		node *t = new node;
		t->data = tmp;
		t->prev = p;
		p = t;
		getline(cin, tmp);
	}
	while (p != head) {//输出
		cout << p->data << endl;
		p = p->prev;
	}
	return 0;
}