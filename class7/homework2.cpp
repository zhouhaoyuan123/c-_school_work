#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; //数列长度,操作次数
	cin >> n >> k;
	vector<int> v;//数列
	for (int i = 0; i < n; i++) { //输入部分
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < k; i++) {
		char op;//操作种类
		cin >> op;
		if (op == 'D') {
			int t;
			cin >> t; //编号
			if (t >= v.size()) {
				//非法
				continue;
			}
			v.erase(v.begin() + t);
		} else if (op == 'Z') {
			int x, y;
			//目标编号,插入的数字
			cin >> x >> y;
			if (x >= v.size()) { //非法
				v.push_back(y);
			} else {
				v.insert(v.begin() + x, y); //插入
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " "; //输出
	}
	return 0;
}