#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; //���г���,��������
	cin >> n >> k;
	vector<int> v;//����
	for (int i = 0; i < n; i++) { //���벿��
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < k; i++) {
		char op;//��������
		cin >> op;
		if (op == 'D') {
			int t;
			cin >> t; //���
			if (t >= v.size()) {
				//�Ƿ�
				continue;
			}
			v.erase(v.begin() + t);
		} else if (op == 'Z') {
			int x, y;
			//Ŀ����,���������
			cin >> x >> y;
			if (x >= v.size()) { //�Ƿ�
				v.push_back(y);
			} else {
				v.insert(v.begin() + x, y); //����
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " "; //���
	}
	return 0;
}