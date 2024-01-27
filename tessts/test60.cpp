#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int n,k;
int arr[MAXN],num[MAXN];
long long int sum[MAXN],ans;

int main() {
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++) {
		scanf("%d",&arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	long long max1 = 0,x1 = 0;
	for(int i = 1;i<=n - k + 1;i++) {
		if(max1 < sum[i+k - 1] - sum[i - 1]) {
			cout << i << " "<<sum[i + k - 1] - sum[i - 1] << " ";
			max1 = sum[i + k - 1] - sum[i - 1];
			x1 = i;
		}
	}
	cout << "   |  ";
	long max2 = 0;
	for(int i = 1;i<=n - k + 1;i++) {
		if(i + k - 1>= x1 && i + k - 1 <= x1 + k - 1) 
		{
			i = x1 + k - 1;
			continue;
		}
		if(i == x1) {
			i += (k - 1);
			//cout << i + 1<<" ";
			continue;
		}
		cout << i << " "<<sum[i + k - 1] - sum[i - 1] << " ";
		if(max2 < sum[i + k - 1] - sum[i - 1]) max2 = sum[i+k - 1] - sum[i - 1];
	}
	cout << max2 + max1;
	return 0;
}
