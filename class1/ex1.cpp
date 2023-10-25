#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};
Node *head, *p, *r;
int x;

int len(Node *head) {
	int n = 0;
	Node *p = head;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void del(Node *head, int i) {
	int j = 2;
	Node *p = head->next;
	while ((p->next != NULL) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) {
		cout << "no this position!";
		return;
	}
	p->next = p->next->next;
}

void insert(Node *head, int i, int x) {
	Node *p, *s;
	int j = 1;
	p = head->next;
	while ((p->next != NULL) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		cout << "no this position!";
		return;
	}
	s = new Node;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

void getNode(Node *head, int i) {
	Node *p;
	int j = 1;
	p = head->next;
	while ((p->next != NULL) && (j < i)) {
		p = p->next;
		j++;
	}
	if (p != NULL && j == i)
		cout >> p->next;
	else
		cout << "i does not exist";
}

int main() {
	head = new Node;
	head->next = NULL;
	r = head;
	cin >> x;
	while (x != -1) {
		p = new node;
		p->data = x;
		p->next = NULL;
		r->next = p;
		r = p;
		cin >> x;
	}
	p = head->next;
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data;
}