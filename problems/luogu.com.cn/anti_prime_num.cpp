#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
long long n;
long long prime[20] = {0,2,3,5,7,11,13,17,19,23,29};
long long maxn = 0,indexn = 0;
void dfs(int step,long long cnt,int j,long long num) {
	if(step == 11) return;
	long long tmp = 1;
	for(int i = 1;i<=j;i++) {
		tmp *= prime[step];
		if(num * tmp > n) break;
		if(num * tmp < indexn && cnt * (i + 1) == maxn) {
			indexn = num * tmp;
		}
		if(cnt * (i + 1) > maxn) {
			maxn = cnt * (i + 1);
			indexn = num * tmp;
		}
		dfs(step + 1,cnt * (i + 1),i,num * tmp);
	}
}

int main() {
	cin>>n;
	dfs(1,1,32,1);
	cout << indexn << endl;
	return 0;
}
