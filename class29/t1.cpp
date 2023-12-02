#include <iostream>
using namespace std;
int N;
int vis[9];
int a[9];
void dfs(int u) {
	if (u == N) {
		for (int i = 0; i < N; i++) {
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		a[u] = i + 1;
		dfs(u + 1);
		a[u] = 0;
	}
}

int main() {
	cin >> N;
	dfs(0);
	return 0;
}
