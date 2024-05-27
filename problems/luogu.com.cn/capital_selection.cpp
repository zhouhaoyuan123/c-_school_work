#include <iostream>
using namespace std;
long long matrix[1005][1005];
long long sum[1005][1005];

int main() {
	int n,m,c;
	cin>>n>>m>>c;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin>>matrix[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
		}
	}
	long long ans = -1e7,ax,ay;
	for(int i =c;i<=n;i++) {
		for(int j = c;j<=m;j++) {
			if(sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c] > ans) {
				ans = sum[i][j] - sum[i - c][j] - sum[i][j - c] + sum[i - c][j - c];
				ax = i;
				ay = j;
			}
		}
	}
	cout << ax - c + 1<<" "<<ay - c + 1;
	return 0;
}
