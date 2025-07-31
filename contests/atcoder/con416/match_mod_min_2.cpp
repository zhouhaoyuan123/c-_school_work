#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int num[300005];
int num2[300005];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
//		memset(num,0,sizeof(num));
//		memset(num2,0,sizeof(num2));
		int n,m;
		scanf("%d%d",&n,&m);
		long long ans = 0;
		for(int i = 1;i<=n;i++) {
			scanf("%d",&num[i]);
			ans += 1ll * num[i];
		}
		for(int i = 1;i<=n;i++) {
			scanf("%d",&num2[i]);
			ans += 1ll * num2[i];
		}
		sort(num+1,num+1+n);
		sort(num2+1,num2+1+n);
		int index = 0;
		for(int i = n;i>=1;i--) {
			while(index <= n && num[i] + num2[index] < m) index ++;
			if(index <= n) {
				ans -= m;
				index ++;
			}
			else break;
		}
		printf("%lld \n",ans);
	}
	printf("\n");
	return 0;
}
