#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> m; //map Ͱ��
	map<int, int> picks; //��ѡ�����б�
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] ++;//����
		if (m[tmp] >= 2) {
			flag = true;
			picks[tmp] = m[tmp];
		}
	}
	int min = -1;
	map<int, int> :: iterator index = picks.begin();
	if (!flag) {
		cout << "No";
		return 0;
	}
	for (map<int, int> :: iterator it = picks.begin(); it != picks.end();) {
		int t = it->first;
		map<int, int> :: iterator tmp = it;
		it++;
		if (it == picks.end()) { //û����
			cout << index -> first;
			return 0;
		}
		if (min > it -> first - t || min == -1 || (min == it -> first - t && index->first > it->first)) {
			//��ͬ�ǿ�first
			min = it -> first - t;
			index = it;
		}
	}
	cout << index->first;
	return 0;
}