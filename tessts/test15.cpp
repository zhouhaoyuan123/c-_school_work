#include <iostream>
#include <string>
using namespace std;

struct node {//�ڵ�ṹ��
	string data;
	node *next;
};

int main() {
	int n;
	cin >> n;
	node head;//ͷ
	bool flag2 = false;//�������Ƿ�Ϊ��
	head.next = NULL;
	//node current;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == 1) { //1����
			flag2 = true;
			string name;
			cin >> name;
			if (flag) {
				head.data = name;//��һ�Σ���ͷ
				// current = head;
				flag = false;
			} else {
				node *current = &head;
				node *no = new node; //�½ڵ�
				no->data = name;
				no->next = NULL;
				while (true) {
					if ((current->data)[0] == name[0]) { //������
						no->next = current->next;//����
						current->next = no;
						break;
					}
					if (current->next == NULL) { //���һ��
						current->next = no;//�ӵ���β
						break;
					}
					current = current->next;//��һ���ڵ�
				}
			}
		} else {
			if (flag2) { //���Ƕ�β
				node current = head;
				cout << current.data << endl;
				if (current.next == NULL) { //���һ��
					flag2 = false;
					node h;
					h.next = NULL;
					head = h;//��ʼ��
					flag = true;
				} else {
					head = *(current.next);
				}
			} else {
				cout << 0;//��
			}
		}
	}
	return 0;
}