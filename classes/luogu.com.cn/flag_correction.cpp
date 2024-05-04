#include <iostream>
using namespace std;
int cnt[55][5];
int n,m;
int dfs(int state,int step,int ans) {
	if(state > 3 || step > n) {
		return 2550;
	}
	//cout << state << " "<<step<<" "<<ans<<endl;
	if(state == 2 && step + 1 == n) {
		return ans + cnt[step][state] + cnt[step+1][state+1];
	}	
	if(state == 1 && step + 2 == n) {
		return ans + cnt[step][state] + cnt[step+1][state+1]+cnt[step+2][state+2];
	}
	if(state == 3 && step == n) {
		return ans + cnt[step][state];
	}
	return min(dfs(state,step+1,ans + cnt[step][state]),dfs(state+1,step+1,ans + cnt[step][state]));
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			char op;
			cin>>op;
			if(op == 'W') {
				cnt[i][2] ++;
				cnt[i][3] ++;
			}
			else if(op == 'B') {
				cnt[i][1] ++;
				cnt[i][3] ++;
			}
			else {
				cnt[i][1] ++;
				cnt[i][2] ++;
			}
		}
	}
	cout << dfs(1,1,0);
	return 0;
}
