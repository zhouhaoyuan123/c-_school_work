#include <cstdio>
#include <iostream>
using namespace std;
int matrix[501][501];

int main() {
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t = 1;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			matrix[i][j] = t++;
		}
	}
	for(int i = 0;i<m;i++) {
		int x,y,r,z;
		cin>>x>>y>>r>>z;
		x-=r + 1;
		y -= r + 1;
		r = 2 * r + 1;
		int tmp[r][r];
		if(z == 0) {
			for(int i = 0,cnt = 0;i<r;i++,cnt++) {
				for(int j = r - 1,cnt2 = 0;j>=0;j--,cnt2++) {
					tmp[cnt][cnt2] = matrix[x + j][y + i];
				}
			}
		}
		else {
			for(int j = r - 1,cnt = 0;j>=0;j--,cnt++) {
				for(int i = 0,cnt2 = 0;i<r;i++,cnt2++) {
					tmp[cnt][cnt2] = matrix[x + i][y + j];
				}
			}
		}
		for(int i = 0;i<r;i++) {
			for(int j = 0;j<r;j++) {
				matrix[x+i][y+j] = tmp[i][j];
			}
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}
