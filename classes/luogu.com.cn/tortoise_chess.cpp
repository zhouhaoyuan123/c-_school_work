#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int value[355];
int cards[125];
int dp[31][13][13][13];
int check[5];

int main() {
//	freopen("tortoise.in","r",stdin);
//	freopen("tortoise.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>value[i];
	}
	for(int i = 1;i<=m;i++) {
		cin>>cards[i];
		check[cards[i]]++;
	}
	dp[1][0][0][0] = value[1];
	for(int i = 2;i<=n;i++) {
		for(int j = 0;j<=check[1];j++) {
			for(int k = 0;k<=check[2];k++) {
				for(int z = 0;z<=check[3];z++) {
					int x = j + k * 2 + z * 3;
					x = i - 1 - x;
					if(x > 0 && x % 4 == 0) {
						int tmp[5] = {0,j,k,z,x / 4};
						for(int h = 1;h<=4;h++) {
							tmp[h] --;
							if(tmp[h] < 0 || i< h) {tmp[h] ++ ;continue;}
							dp[i][j][k][z] = max(dp[i - h][tmp[1]][tmp[2]][tmp[3]] + value[i],dp[i][j][k][z]);
							tmp[h] ++;
						}
					}
				}
			}
		}
	}
	cout << dp[n][check[1]][check[2]][check[3]];
	return 0;
}
