#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int rect[1005][4];
int point[4005],point2[4005];
int vis[4005][4005];
int n,m,m2;

int search(int point[],int target,int m) {
	int l = 1,r = m;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(point[mid] == target) {
			return mid;
		}
		if(point[mid]<target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}

int main() {
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>rect[i][0]>>rect[i][1]>>rect[i][2]>>rect[i][3];
		point[++m] = rect[i][0];
		point[++m] = rect[i][2];
		point2[++m2] = rect[i][1];
		point2[++m2] = rect[i][3];
	}
	sort(point+1,point+1+m);
	sort(point2+1,point2+1+m2);
	m = unique(point+1,point+1+m) - point;
	m2 = unique(point2+1,point2+1+m2) - point2;
	for(int i = 1;i<=n;i++) {
		int x1 = search(point,rect[i][0],m),y1 = search(point2,rect[i][1],m2),x2 = search(point,rect[i][2],m),y2 = search(point2,rect[i][3],m2);
//		vis[x1][y1] = 1;
//		vis[x1][y2] = 1;
//		vis[x2][y1] = 1;
//		vis[x2][y2] = 1;
//		cout << x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		for(int i = min(x1,x2);i<max(x1,x2);i++) {
			for(int j = min(y1,y2);j<max(y1,y2);j++) {
				vis[i][j] = 1;
			}
		}
	}
//	for(int i = 1;i<=m;i++) {
//		for(int j = 1;j<=m2;j++) {
//			cout << vis[i][j]<<" ";
//		}
//		cout << endl;
//	}
	long long ans = 0;
	for(int i = 1;i<m;i++) {
		for(int j = 1;j<m2;j++) {
			if(vis[i][j]) {
				ans += 1ll * (point[i+1] - point[i]) * (point2[j+1] - point2[j]);
			}
		}
	}
	cout << ans;
	return 0;
}
