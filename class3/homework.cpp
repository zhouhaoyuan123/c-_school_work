#include <iostream>
#include <string>
using namespace std;

struct node {
	int cnt;
	int num[10005];
};

int main() {
	int n;
	cin >> n;
	node chain[n + 5];
	int start = 1;
	for (int i = 0; i < n; i++) { //��ʼ��
		chain[i + 1].cnt = 0;
		chain[i + 1].num[chain[i + 1].cnt] = i + 1; //��������
//		cout <<	chain[i + 1].num[chain[i + 1].cnt] << endl;
		chain[i + 1].cnt++;

	}
	for (int i = 0; i < (n - 1); i++) {
		int x, y;
		cin >> x >> y;
		start = x;//����xΪ����Ԫ�أ�̰�ģ�
		for (int j = 0; j < chain[y].cnt; j++) {
			chain[x].num[chain[x].cnt] = chain[y].num[j];//����
			chain[x].cnt++;
		}
//		node tmp;
//		tmp.cnt = 0;
//		chain[y] = tmp;//���
	}
	for (int i = 0; i < chain[start].cnt; i++) {
		cout << chain[start].num[i] << endl;//���
	}
	return 0;
}