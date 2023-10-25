#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 1010;
int n, a[maxn], b[maxn], num[2 * maxn],sum[maxn] = {0};
map < int, int > T;
int main() {
//	freopen("room.in","r",stdin);
//	freopen("room.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		T[a[i]] = 1;
		T[b[i] + 1] = 1;
	}
	int i = 1;
	for(auto it = T.begin();it != T.end() ;it++) {
		it -> second = i++;
	}
	int maxx = 0;
	for(i = 1;i<=n;i++) {
		for(int j = T[a[i]],cnt = a[i] ; j< T[b[i] + 1];j++,cnt++) {
			num[j] ++;
			if(j == T[b[i] + 1] - 1) {
				cout << maxx << " : "<<cnt - a[i]<<endl;
				sum[maxx] += cnt - a[i];
			}
			if(num[j] != maxx) {
				cout << maxx << " : "<<cnt - a[i]<<endl;
				sum[maxx] += cnt - a[i];
			}
			if(num[j] > maxx) {
				maxx = num[j];
				//z = b[i] - a[i] + 1;
			}
		}
		//sum[maxx] += b[i] - a[i] + 1;
	}
	cout << maxx << " " << sum[maxx] << endl;
	return 0;
}

