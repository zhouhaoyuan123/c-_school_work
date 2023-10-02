#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
long long sum = 0;
int n;
map<int,map<int,bool> > vis;
void calc(int m,int f) {
	if(vis[m][f]) {
		return;
	}
	vis[m][f] = 1;
	if(n < m + f) {
		return;
	}
	if((n - m - f) % 3 == 0 && m * 5 + f * 3 + (n - m - f) / 3  == n) {
		sum++;
	}
	calc(m,f+1);
	calc(m+1,f);
	calc(m+1,f+1);
}

int main() {
	//freopen("kfc.in","r",stdin);
	//freopen("kfc.out","w",stdout);
	cin>>n;
	calc(0,0);
	cout << sum;
	return 0;
}
