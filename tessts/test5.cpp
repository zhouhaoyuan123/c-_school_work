#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
//	freopen("ball.in", "r", stdin);
//	freopen("ball.out", "w", stdout);
	scanf("%d%d", &m, &n);
	int ball[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &ball[i]);
	}
	sort(ball, ball + m);
	for (int i = 0; i < n; i++) {
		int id;
		bool flag  = false;
		scanf("%d", &id);
		for (int j = 0; j < m; j++) {
			if (ball[j] == id) {
				printf("YES\n");
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		} else {
			printf("NO\n");
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}