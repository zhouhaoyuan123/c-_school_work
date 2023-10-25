#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n,r;
	cin>>n>>r;
	int bottle[n];
	for(int i = 0;i<n;i++) {
		cin>>bottle[i];
	}
	sort(bottle,bottle+n);
	int sum[101] = {0},ans = 0;
	for(int i = 0,cnt = 0;i<n;i++,cnt++) {
		cnt = cnt % 2;
		ans+=sum[cnt] + bottle[i];
		sum[cnt]+=bottle[i];
	}
	cout << ans;
	return 0;
}
