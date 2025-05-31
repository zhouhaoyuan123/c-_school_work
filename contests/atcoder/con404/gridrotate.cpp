#include <iostream>
using namespace std;
bool S[4][105][105],T[105][105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j = 0;j<s.size();j++) {
			if(s[j] == '.') {
				S[0][i][j+1] = 0;
			}
			else {
				S[0][i][j+1] = 1;
			}
		}
	}
	for(int i = 1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j = 0;j<s.size();j++) {
			if(s[j] == '.') {
				T[i][j+1] = 0;
			}
			else {
				T[i][j+1] = 1;
			}
		}
	}
	for(int i = 0;i<3;i++) {
		for(int j = 1;j<=n;j++) {
			for(int k = 1;k<=n;k++) {
				S[i + 1][k][n - j + 1] = S[i][j][k];
			}
		}
	}
	int sum = n * n + 1;
	for(int i = 0;i<=3;i++) {
		int ans = i;
		for(int j = 1;j<=n;j++) {
			for(int k = 1;k<=n;k++) {
				if(S[i][j][k] != T[j][k]) {
					ans ++;
				}
			}
		}
		sum = min(sum,ans);
	}
	cout << sum << endl;
	return 0;
}
