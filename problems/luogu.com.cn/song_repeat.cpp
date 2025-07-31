#include <iostream>
using namespace std;
long long num[100005];

int main() {
	int n;
	cin>>n;
	__int128 cnt = 0;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		cnt += num[i];
	}
	long long T;
	cin>>T;
	__int128 tmp = 0;
	for(int i = 1;i<=n;i++) {
		if(tmp >= (T % cnt)) {
			if(i - 1 <= 0) {
				cout << n << endl;
				return 0;
			}
			cout << i - 1 << endl;
			return 0;
		}
		tmp += num[i];
		if(tmp >= (T % cnt)) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
