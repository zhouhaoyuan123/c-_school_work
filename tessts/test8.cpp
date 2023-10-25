#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct name {
	char n[25];
};

bool cmp(name x, name y) {
	return strcmp(x.n, y.n) < 0;
}

int main() {
	int i = 0;
	name na[5];
	while (scanf("%s", na[i].n) != EOF) {
		i++;
	}
	sort(na, na + i, cmp);
	for (int j = 0; j < i; j++) {
		printf("%s\n", na[j].n);
	}
	return 0;
}