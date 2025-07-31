#include <iostream>
#include <vector>
using namespace std;
vector<long long> maze[200005];
vector<long long> num[200005];
long long p[400005];

int main() {
	int H,W;
	cin>>H>>W;
	for(int i = 0;i<=W;i++) {
		num[0].push_back(0);
		num[H+1].push_back(1e17);
	}
	for(int i = 1;i<=H;i++) {
		maze[i].push_back(0);
		num[i].push_back(0);
		for(int j = 1;j<=W;j++) {
			long long x;
			cin>>x;
			maze[i].push_back(x);
			num[i].push_back(0);
		}
		num[i].push_back(1e17);
	}
	num[H + 1][W] = 0;
	num[H][W + 1] = 0;
	for(int i = 1;i<=H + W - 1;i++) {
		cin>>p[i];
	}
	for(int i = H;i>=1;i--) {
		for(int j = W;j>=1;j--) {
			//num[i][j] = min(1ll*0,min(p[i + j - 1] - num[i][j],max(p[i + j - 1] - maze[i][j] + num[i + 1][j],p[i + j - 1] - maze[i][j] + num[i][j + 1])));
			//min(1ll*0,min(p[i + j - 1] - num[i][j],max(p[i + j - 1] - maze[i][j] + num[i + 1][j],p[i + j - 1] - maze[i][j] + num[i][j + 1])));
			num[i][j] = min(
				max(1ll * 0,max(p[i + j - 1] - maze[i][j],p[i + j - 1] - maze[i][j] + num[i + 1][j])),
				max(1ll * 0,max(p[i + j - 1] - maze[i][j],p[i + j - 1] - maze[i][j] + num[i][j + 1]))
			);
			//cout << num[i][j] << " ";
		}
				//cout << endl;
	}
	if(num[1][1] >= 0) {
		cout << num[1][1] << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
} 
