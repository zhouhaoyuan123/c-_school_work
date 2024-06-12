#include <iostream>
using namespace std;
int n;
int num[15];
int ans[59055][11];
int sum;
void dfs(int step,int cnt) {
    if(cnt > n) {
        return;
    }
    if(step > 10 && cnt == n) {
        //cout << cnt<<" ";
        ++sum;
        for(int i = 1;i<=10;i++) {
            ans[sum][i] = num[i];
        }
        return;
    }
    if(step > 10) return;
    for(int i = 1;i<= 3;i++) {
        num[step] = i;
        dfs(step+1,cnt + i);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios :: sync_with_stdio(0);
    cin>>n;
    dfs(1,0);
    for(int i = 1;i<=sum;i++) {
        for(int j = 1;j<=10;j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    } 
    if(sum == 0) {
        cout << 0;
    }
    return 0;
}