#include <iostream>
#include <algorithm>
using namespace std;
long long num[500005];
bool vis[500005];

int main() {
	int N;
	cin>>N;
	for(int i = 1;i<=N;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+N,greater<long long> ());
	long long ans = 0;
	int index = 3;
	for(int i = 1;i<=N;i++) {
		i++;
		if(vis[i]) continue;
		index = max(index,i);
		while(index<=N) {
			if(!vis[index] && num[index] * 2 <= num[i]) {
				break;
			}
			index ++;
		}
		vis[index] = 1;
		index ++;
	}
	for(int i = 1;i<=N;i++) if(!vis[i]) ans += num[i];
	cout << ans << endl;
	return 0;
}
