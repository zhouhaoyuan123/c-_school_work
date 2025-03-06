#include <iostream>
using namespace std;
int carpets[10005][4];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>carpets[i][0] >> carpets[i][1] >> carpets[i][2] >> carpets[i][3];
	}
	int x,y;
	cin>>x>>y;
	int ans = -1;
	for(int i = 1;i<=n;i++) {
		if(x >= carpets[i][0] && x <= carpets[i][0] + carpets[i][2] && y >= carpets[i][1] && y <= carpets[i][3] + carpets[i][1]) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
