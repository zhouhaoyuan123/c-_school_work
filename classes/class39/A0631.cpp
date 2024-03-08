/*
  @id A0631
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct clothe {
	long long p,a,b;
	friend bool operator < (clothe x,clothe y) {
		return x.p > y.p;
	}
};
int n;
clothe clothes[200005]; 
priority_queue <clothe> q[5][5];
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>clothes[i].p;
	}
	for(int i = 0;i<n;i++) {
		cin>>clothes[i].a;
	}
	for(int i = 0;i<n;i++) {
		cin>>clothes[i].b;
		q[clothes[i].a][clothes[i].b].push(clothes[i]);
	}
	int m;
	cin>>m;
	for(int i = 0;i<m;i++) {
		int tmp;
		cin>>tmp;
		long long ans = 2e9,index = -1;
		for(int i = 1;i<=3;i++) {
			if(!q[tmp][i].empty()) {
				if(ans > q[tmp][i].top().p) {
					ans = q[tmp][i].top().p;
					index = i;
				}
			}
		}
		long long ans2 = 2e9,index2 = -1;
		for(int i = 1;i<=3;i++) {
			if(!q[i][tmp].empty()) {
				if(ans2 > q[i][tmp].top().p) {
					ans2 = q[i][tmp].top().p;
					index2 = i;
				}
			}
		}
		if(ans > ans2) {
			ans = ans2;
			q[index2][tmp].pop();
			cout << ans<<" ";
		}
		else if(index == -1 && index2 == -1) {
			cout << -1 <<" ";
		}
		else {
			cout << ans<<" ";
			q[tmp][index].pop();
		}
	}
	
	return 0;
}

