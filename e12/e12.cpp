#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
long long generate_num(int i, int j) {
	long long sum = 0;
	for (int x = i; x <= j; x++) {
		sum *= 10;
		sum += numbers[x];
	}
	return sum;
}

bool check(long long n) {
	//cout << n << endl;
	bool is_used[10] = {0};
	is_used[0] = true;
	int sum = 9;
	while (n > 0) {
		if (is_used[n % 10]) {
			return false;
		}
		is_used[n % 10] = true;
		n /= 10;
		sum--;
	}
	if (sum > 0) {
		return false;
	}
	return true;
}

int main() {
	//freopen("formula.in","r",stdin);
	//freopen("formula.out","w",stdout);
	long long cnt = 0;
	do {
		for (int i = 1; i < 9; i++) { //¡ÁºÅÎ»ÖÃ
			if (check(generate_num(0, i - 1) * generate_num(i, 8))) {
				cnt++;
			}
		}
	} while (next_permutation(numbers, numbers + 9));
	// cout << cnt;
	// return 0;
	long long x, y;
	cin >> x >> y;
	cout << cnt << endl;
	cout << cnt *x + y;
	return 0;
}