#include <iostream>
#include <iomanip>
using namespace std;
int n,k;
bool vis[25];
int num[25];
int ans = 0;
int matches[1000005] = {6,2,5,5,4,5,6,3,7,6,0};
int cnt_match(int n) {
    return matches[n];
}

void dfs(long long i,int step,int cnt) {
	if(step == k) {
        //cout << num[0]<<" "<<num[1]<<endl;
		if(cnt_match(num[0] + num[1]) == n - cnt) {
            ans++;
        }
		return;
	}
    if(n - cnt <= 0) return;
	for(int j = 0;j<=9;j++) {
		if(i == 0 && j == 0) {
            //cnt += matches[0];
            num[step] = 0;
            dfs(0,step + 1,cnt + matches[0]);
            continue;
        }
        dfs(i * 10 + j,step,cnt + matches[j]);
        num[step] = i * 10 + j;
        dfs(0,step + 1,cnt + matches[j]);
	}
}

int main() {	
	cin>>n;
	n -= 4;
    k = 2;
    for(int i = 10;i<=10000;i++) {
        matches[i] = matches[i / 10] + matches[i % 10];
    }
    for(int i = 0;i<=2000;i++) {
        for(int j = 0;j<=2000;j++) {
            if(matches[i] + matches[j] + matches[i + j] == n) {
                ans ++;
            }
        }
    }
    cout << ans;
	return 0;
}