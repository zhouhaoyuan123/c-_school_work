#include<iostream>
using namespace std;
int n;
int ans[100];
void answer() {
	for(int i = 1;i<=n;i++) {
		cout << ans[i];
	}
	cout << endl;
}
void solve(int x) {
	if(x>n) {
		answer();
		return;
	}
	ans[x] = 0;
	solve(x+1);
	ans[x] = 1;
	solve(x+1);
}
int main() {
	cin>>n;
	solve(1);
	return 0;
}
