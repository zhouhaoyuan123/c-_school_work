#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long n,m;
	cin>>n>>m;
	long long height[n];
	for(long long i = 0;i<n;i++) {
		cin>>height[i];
	}
	for(long long i = 0;i<m;i++) {
		long long heightcow;long long base = 0;
		cin>>heightcow;
		for(long long j = 0;j<n;j++) {
			if(height[j] >= heightcow && heightcow > base) {
				long long tmp = height[j];
				height[j] += (heightcow - base);
				base += tmp;break;
			}
			else if(height[j] >= base && heightcow > base) {
				long long tmp = height[j];
				height[j] += (height[j]- base);
				base += (tmp- base);
			}
		}
	}
	for(long long i = 0;i<n;i++) {
		cout << height[i]<<endl;
	}
	return 0;
}
