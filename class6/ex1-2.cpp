#include <iostream>
using namespace std;

long long a, n;
long long q[1000005];

int main() {
	cin >> a >> n;
	q[1] = a;
	long long two = 1, three = 1, rear = 1;
	while (rear < n) {
		if (q[two] * 2 + 1 < q[three] * 3 + 1) {
			rear++;
			q[rear] = q[two] * 2 + 1;
			two++;
		} else if (q[two] * 2 + 1 > q[three] * 3 + 1) {
			rear++;
			q[rear] = q[three] * 3 + 1;
			three++;
		} else {
			rear++;
			q[rear] = q[three] * 3 + 1;
			three++;
			two++;
		}
	}
	cout << q[rear];
	return 0;
}