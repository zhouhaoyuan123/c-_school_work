#include <iostream>
using namespace std;
long long memory[1000005];

long long f(long long n) {
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	if (memory[n] != 0) {
		return memory[n];
	}
	long long sum = 0;
	for (int i = 2; i <= n; i++)  {
		if (n % i == 0) {
			sum += (f((n / i)) % 1000000007 + i % 1000000007) % 1000000007;
		}
	}
	memory[n] = sum;
	return sum;
}

int main() {
	long long n;
	cin >> n;
	cout << f(n);
	return 0;
}