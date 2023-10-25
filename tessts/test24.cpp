#include <iostream>
using namespace std;
int cnt = 0, num = 0, num2 = 0;

int gift[15] = {0}, noaccept[15];

void f(int n) {//»À
	if (num < n) { //Ω· ¯
		cnt++;
		return;
	}
	for (int i = 1; i <= num; i++) {
		if (gift[i] == 0 && noaccept[i] != n) {
			gift[i] = n;
			cout << i << " " << gift[i] << endl;
			f(n + 1);
		}
	}
}

int main() {
	cin >> num >> num2;
	for (int i = 0; i < num2; i++) {
		int gift2, person;
		cin >> person >> gift2;
		noaccept[gift2] = person;
	}
	f(1);
	cout << cnt ;
	return 0;
}