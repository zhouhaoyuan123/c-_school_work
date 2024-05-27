#include <iostream>
using namespace std;
int num[305];
bool vis[305];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	int cur = 0;
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		int index = 0,tmp = 0;
		for(int j = 1;j<=n;j++) {
			if(!vis[j] && cur != j) {
				if(abs(num[j] - num[cur]) > tmp) {
					index = j;
					tmp = abs(num[j] - num[cur]);
				}
			}
		}
		vis[index] = 1;
		vis[cur] = 1;
		ans += abs(num[index] - num[cur]) * abs(num[index] - num[cur]);
		cur = index;
	}
	cout << ans;
	return 0;
}

