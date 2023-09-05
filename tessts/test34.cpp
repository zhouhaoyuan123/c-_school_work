#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct point {
	int l,r,f,b,c;  
};
int main() {
	//freopen("laser.in","r",stdin);
	//freopen("laser.out","w",stdout);
	int n;cin>>n;
	int maxn = 0;
	point enemy[n][n];
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			int tmp;cin>>tmp;
			enemy[i][j].c = tmp;
			enemy[i][j].l = tmp;
			enemy[i][j].f = tmp;  
			enemy[i][j].r = tmp;
			enemy[i][j].b = tmp;  
			if(j != 0) {
				enemy[i][j].l = enemy[i][j - 1].l + enemy[i][j].c;
			}
			//enemy[i][j].r =
			if(i != 0) {
				enemy[i][j].f = enemy[i - 1][j].f+enemy[i][j].c;   
			}
			//enemy[i][j].b = enemy[i+1][j].b+ene
		}
		for(int j = 0;j<n;j++) {
			if(j != n - 1) {
				enemy[i][j].r = enemy[i][n - 1].l  - enemy[i][j].l +  enemy[i][j].c;
			}
			//enemy[i][j].r =
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(i != n - 1) {
				enemy[i][j].b = enemy[n - 1][j].f - enemy[i][j].f + enemy[i][j].c;   
			}
			if(enemy[i][j].c == 0) {
				maxn = max(maxn,enemy[i][j].l + enemy[i][j].f + enemy[i][j].b + enemy[i][j].r);
			}
		}
	}
	cout << maxn;
	return 0;
}
