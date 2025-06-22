#include <iostream>
using namespace std;
int ans[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int a;
		cin>>a;
		ans[a] ++;
	}
	int cnt = 0;
	for(int i = 1;i<=100000;i++) {
		cnt = cnt - min(cnt,ans[i]) + ans[i];
	}
	cout << cnt << endl;
	return 0;
}
