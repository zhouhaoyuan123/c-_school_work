#include <iostream>
using namespace std;
int num[1005];
bool vis[1005];

int main() {
	int n;
	cin>>n;
	int ans = n - 1;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i = 1;i<n;i++) {
		if(abs(num[i] - num[i + 1]) >= 1 && abs(num[i] - num[i + 1]) < n && !vis[abs(num[i] - num[i + 1])]) {
			ans --;
			vis[abs(num[i] - num[i + 1])] = true;
		}
	}
	if(ans == 0) {
		cout << "Jolly";
	}
	else {
		cout << "Not jolly";
	}
	return 0;
}
