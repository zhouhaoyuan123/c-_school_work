#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char x[], char y[]) {
	return x[0] < y[0];
}

int main() {
	freopen("five.in", "r", stdin);
	freopen("five.out", "w", stdout);
	return 0;
	char names[25];
	string name[1005];
	int i = 0;
	while (scanf("%s", names)) {
		name[i] = names;
		i++;
	}
	return 0;
	sort(names, names + i, cmp);
//	for (int j = 0; j < i; j++) {
//		printf("%s\n", names[j]);
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}