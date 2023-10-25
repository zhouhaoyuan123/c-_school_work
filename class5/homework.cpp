#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int num;
	cin >> num;
	int qn[n], frontn = 0, rearn = 0;
	int qm[m], frontm = 0, rearm = 0;
	for (int i = 0; i < n; i++) {
		qn[rearn] = i + 1;
		rearn++;
	}
	for (int i = 0; i < m; i++) {
		qm[rearm] = i + 1;
		rearm++;
	}
	for (int i = 0; i < num; i++) {
		//cout
		//front++;rear % n m rear++
		int t1 = qn[frontn], t2 = qm[frontm];
		cout << t1 << " " << t2 << endl;
		frontn++;
		frontm++;
		frontn = frontn % n;
		frontm = frontm % m;
		rearn = rearn % n;
		rearm = rearm % m;
		qn[rearn] = t1;
		qm[rearm] = t2;
		rearn++;
		rearm++;
	}
	return 0;
}