#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
int dis[200005];
int opdis[200005];
int input[200005][3];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		char op;
		cin>>op;
		if(op == '+') {
			input[i][0] = 0;
			cin>>input[i][1] >> input[i][2];
		}
		else {
			input[i][0] = 1;
			cin>>input[i][1] >> input[i][2];
		}
	}
	opdis[m] = 1;
	for(int i = m;i>=1;i--) {
		opdis[i] = (opdis[i] + opdis[i + 1]) % mod;
		if(input[i][0]) {
			opdis[input[i][2]] += opdis[i];
			opdis[input[i][1] - 1] -= opdis[i];
			opdis[input[i][1] - 1] += mod;
			opdis[input[i][2]] %= mod;
			opdis[input[i][1] - 1] %= mod;
		}
		else {
			dis[input[i][1]] += opdis[i];
			dis[input[i][2] + 1] -= opdis[i];
			dis[input[i][2] + 1] += mod;
			dis[input[i][1]] %= mod;
			dis[input[i][2] + 1] %= mod;
		}
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += dis[i];
		ans %= mod;
		cout << ans <<  "\n";
	}
	cout << endl;
	return 0;
}
