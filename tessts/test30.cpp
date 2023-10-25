#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	//freopen("flower.in","r",stdin);
	//freopen("flower.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int lit[n];
	int pe[m];
	for (int i = 0; i < n; i++) {
		cin >> lit[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> pe[i];
	}

	for (int i = 0; i < n; i++) {
		//cout << lit[i]<<" ";
		if (binary_search(pe, pe + m, lit[i])) {
			cout << lit[i] << " ";
		}
	}
	return 0;
}