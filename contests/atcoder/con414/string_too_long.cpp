#include <iostream>
using namespace std;
char c[105];
long long l[105];

int main() {
	int N;
	cin>>N;
	long long ans = 0;
	for(int i = 1;i<=N;i++) {
		cin>>c[i]>>l[i];
		if(l[i] > 100) {
			cout << "Too Long" << endl;
			return 0;
		}
		ans += l[i];
		if(ans > 100) {
			cout << "Too Long" << endl;
			return 0;
		}
	}
	for(int i = 1;i<=N;i++) {
		for(int j = 1;j<=l[i];j++) {
			cout << c[i];
		}
	}
	cout << endl;
	return 0;
}
