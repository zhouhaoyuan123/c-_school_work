#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
int n, next_num[1000005], next2[10000005];
map<int,int> tree;
int num[1000005], ans[1000005];
void dfs(int dep, int step, int index) {
	if (step == -1) {
		return;
	}
	tree[index] = num[step];
	dfs(dep + 1, next_num[step], index * 2);
	dfs(dep + 1, next2[step], index * 2 + 1);
}
int calc(bool mode, int index, int step, int mirror) {
	if (!tree.count(index) || (!mode && tree[index] != tree[mirror])) {
		return step - 1;
	}
	if (!mode && ans[index]) return ans[index];
	if (mode) {
		ans[index] = calc(0, index * 2, 1, mirror * 2 + 1) * 2 + 1;
		int tmp = ans[index];
		if (index % 2 == 0) {
			if (!tree.count(index+1) || tree[index + 1] != tree[index])
				ans[index] = 1;
		} else {
			if (!tree.count(index / 2 * 2) || tree[index / 2 * 2] != tree[index])
				ans[index] = 1;
		}
		return tmp;
	} else {
		ans[index] = calc(0, index * 2, 1, mirror * 1 + 1) * 2 + 1;
		return ans[index];
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> next_num[i] >> next2[i];
	}
	dfs(1, 1, 1);
	int fans = 0;
	for (int i = 1; i <= n; i++) {
		fans = max(fans, calc(1, i, 1, i));
	}
	cout << fans;
	return 0;
}
