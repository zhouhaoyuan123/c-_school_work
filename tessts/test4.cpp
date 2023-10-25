#include <iostream>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, k;

	freopen("hike.in", "r", stdin);
	freopen("hike.out", "w", stdout);
	scanf("%d%d", &n, &k);

	int length[n - 1];
	for (int i = 0; i < (n - 1); i++) {
		scanf("%d", &length[i]);
	}
	for (int i = 0; i < k; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		printf("%d", length[t1 - 1]);
		printf(" ");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}