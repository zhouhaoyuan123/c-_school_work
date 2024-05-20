#include <iostream>
using namespace std;
int r,c,a,b;
int matrix[505][505];
long long sum[505][505];
bool judge(int lim) {
	int cnt = 0,cur = 0;
	for(int i = 1;i<=r;i++) {
		int tmp = 0,end_i = 0;
		for(int j = 1;j<=c;j++) {
			if(tmp==b) {
				cur = i;
				cnt++;
				break;
			}
			if(sum[i][j] - sum[i][end_i] - sum[cur][j] + sum[cur][end_i] >= lim) {
				end_i = j;
				tmp++;
			}
		}
		if(tmp == b) {
			cur = i;
			cnt++;
		}
	}
	return cnt >= a;
}

int main() {
	cin>>r>>c>>a>>b;
	for(int i = 1;i<=r;i++) {
		for(int j = 1;j<=c;j++) {
			cin>>matrix[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
		}
	}
	long long l = 0,r1 = sum[r][c];
	while(l<r1) {
		long long mid = (l + r1+1) / 2;
		if(judge(mid)) {
			l = mid;
		}
		else {
			r1 = mid - 1;
		}
	}
	cout << l;
	return 0;
}
