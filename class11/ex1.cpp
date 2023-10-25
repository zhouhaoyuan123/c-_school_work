#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 1;
	string storage[n];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s; //输入
		//尝试把s这个树融入主树
		int min = s.size();//（至少）要新增几个
		for (int j = 0; j < i; j++) {
			bool flag = true;
			for (int z = 0, cnt = 0; cnt < s.size(); z++, cnt++) {
				if (z >= storage[j].size()) {
					flag = false;
					if (min > s.size() - z) {
						min = s.size() - z;
					}
					break;
				}
				if (cnt >= s.size()) {
					min = 0;
					break;
				}
				if (storage[j][z] != s[cnt]) {
					flag = false;
					if (min > s.size() - cnt) {
						min = s.size() - cnt;
					}
					break;
				}
			}
			if (flag) {
				min = 0;
			}
		}
		ans += min;
		storage[i] = s;
		sort(storage, storage + i + 1);
	}
	cout << ans ;
	return 0;
}