#include <iostream>
#include <cmath>
using namespace std;
int num[105];

int main() {
	int n;
	cin>>n;
	for(int i = n;i>=0;i--) {
		cin>>num[i];
	}
	for(int i = n;i>=0;i--) {
		if(num[i] == 0) continue;
		if(abs(num[i]) != 1) {
			if(num[i] > 0) {
				if(i == n) {
					cout << num[i];
				}
				else {
					cout << "+" << num[i];
				}
			}
			else {
				cout << num[i];
			}
		}
		else {
			if(num[i] > 0) {
				if(i != n) {
					cout << "+";
				}
			}
			else {
				cout << "-";
			}
			if(i == 0) {
				cout << abs(num[i]);
			}
		}
		if(i > 0) {
			cout << "x";
		}
		if(i > 1) {
			cout << "^" << i;
		}
	}	
	cout << endl;
	return 0;
}
