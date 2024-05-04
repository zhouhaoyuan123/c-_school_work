#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int num1[505],num2[505],jinwei[505],res[505];

int main() {
	cin>>s1>>s2;
	int L1 = s1.size();
	int L2 = s2.size();
	for(int i = 0;i<L1;i++) {
		num1[L1 - 1 - i] = s1[i] - '0';
	}
	for(int i = 0;i<L2;i++) {
		num2[L2 - 1 - i] = s2[i] - '0';
	}
	int L3 = max(L1,L2) + 1;
	for(int i = 0;i<L3;i++) {
		jinwei[i] = num1[i] + num2[i]+jinwei[i];
		jinwei[i+1] = jinwei[i] / 10;
		jinwei[i] %= 10;
	}
	for(int i = L3 - 1;i>=0;i--) {
		if(i == L3 - 1 && jinwei[i] == 0) {
			continue;
		}
		cout << jinwei[i];
	}
	return 0;
}
