#include<bits/stdc++.h>
using namespace std;
int dp[401][401],V,W,v[51],w[51],k[51],n;
int main() {
	cin >> V >> W >> n;//v体积，w质量，n个数
	for(int i = 1;i <= n;i++) 
		cin >> v[i] >> w[i] >> k[i];
	for(int i = 1;i <= n;i++) 
		for(int j = V;j >= v[i];j--) 
			for(int z = W;z >= w[i];z--) 
				dp[j][z] = max(dp[j][z],dp[j - v[i]][z - w[i]] + k[i]);
	cout << dp[V][W];
	return 0;
}

