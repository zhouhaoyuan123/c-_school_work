#include <iostream>
#include <cstdio>
using namespace std;

int main() {
//	freopen("mul.in", "r", stdin);
//	freopen("mul.out", "w", stdout);
	int number1[15];
	int number2[25];
	int ans[25] = {0}, t[4];
	for (int i = 0; i <= 2; i += 2) {
		int a, b;
		cin >> a >> b;
		t[i] = a;
		t[i + 1] = b;
		//number1[b] = a;
	}
	//return 0;
	for (int i = 0; i <= 2; i += 2) {
		int a, b;
		cin >> a >> b;
		//number2[b] = a;
		for (int j = 0; j <= 2; j += 2) {
			ans[t[j + 1] + b] += a * t[j];
		}
	}
	//return 0;
	for (int i = 20; i >= 0; i--) {
		if (ans[i] != 0) {
			cout << ans[i] << " " << i  << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}