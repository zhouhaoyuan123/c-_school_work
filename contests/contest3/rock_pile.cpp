#include <iostream>
#include <cstring>
using namespace std;

long long digits[100005];
char num[100005];

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>num;
		long long cnt = 0;
		long long p = 1;
		for(int i = strlen(num) - 1;i>=0;i--) {
			if(num[i] != '0') {
				cnt += p;
			}
			p *= 10;
		}
		if(cnt % 2 == 0) {
			cout << "E"<<endl;
		}
		else {
			cout << "B"<<endl;
		}
	}
	return 0;
}
