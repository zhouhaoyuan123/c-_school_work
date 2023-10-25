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
	for (int i = 0; i < n; i++) { //初始化
		chain[i + 1].cnt = 0;
		chain[i + 1].num[chain[i + 1].cnt] = i + 1; //加入数组
//		cout <<	chain[i + 1].num[chain[i + 1].cnt] << endl;
		chain[i + 1].cnt++;

	}
	for (int i = 0; i < (n - 1); i++) {
		int x, y;
		cin >> x >> y;
		start = x;//假设x为最终元素（贪心）
		for (int j = 0; j < chain[y].cnt; j++) {
			chain[x].num[chain[x].cnt] = chain[y].num[j];//拷贝
			chain[x].cnt++;
		}
//		node tmp;
//		tmp.cnt = 0;
//		chain[y] = tmp;//清空
	}
	for (int i = 0; i < chain[start].cnt; i++) {
		cout << chain[start].num[i] << endl;//输出
	}
	return 0;
}