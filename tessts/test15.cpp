#include <iostream>
#include <string>
using namespace std;

struct node {//节点结构体
	string data;
	node *next;
};

int main() {
	int n;
	cin >> n;
	node head;//头
	bool flag2 = false;//：链表是否为空
	head.next = NULL;
	//node current;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == 1) { //1功能
			flag2 = true;
			string name;
			cin >> name;
			if (flag) {
				head.data = name;//第一次，队头
				// current = head;
				flag = false;
			} else {
				node *current = &head;
				node *no = new node; //新节点
				no->data = name;
				no->next = NULL;
				while (true) {
					if ((current->data)[0] == name[0]) { //是朋友
						no->next = current->next;//插入
						current->next = no;
						break;
					}
					if (current->next == NULL) { //最后一个
						current->next = no;//加到队尾
						break;
					}
					current = current->next;//下一个节点
				}
			}
		} else {
			if (flag2) { //不是队尾
				node current = head;
				cout << current.data << endl;
				if (current.next == NULL) { //最后一个
					flag2 = false;
					node h;
					h.next = NULL;
					head = h;//初始化
					flag = true;
				} else {
					head = *(current.next);
				}
			} else {
				cout << 0;//无
			}
		}
	}
	return 0;
}