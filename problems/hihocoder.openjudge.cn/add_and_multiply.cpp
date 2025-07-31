#include <iostream>
using namespace std;
const int mod = 1e9+7;
int input[200005][4];
int ans[200005];

int main() {
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=q;i++) {
		char op;cin>>op;
		if(op == '+') {
			input[i][0] = 1;
			cin>>input[i][1]>>input[i][2];
		}
		else {
			input[i][0] = 2;
			cin>>input[i][1];
		}
	}
	long long num = 1;
	for(int i = q;i>=1;i--) {
		if(input[i][0] == 1) {
			ans[input[i][1]] += num * input[i][2] % mod;
			ans[input[i][1]] %= mod;
		}
		else {
			num = num * input[i][1] % mod;
		}
	}
	for(int i = 1;i<=n;i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
