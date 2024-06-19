#include <iostream>
using namespace std;
long long dp[25][25];
bool deny[25][25];
int dir[9][2] = {{0,0},{1,2},{-1,2},{1,-2},{-1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};

int main() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x ++,y++;
    for(int i = 0;i<9;i++) {
        if(1 <= x + dir[i][0]&&x + dir[i][0] <= n + 1 && 1 <= y + dir[i][1]&&y + dir[i][1] <= m + 1)
            deny[x + dir[i][0]][y + dir[i][1]] = true;
        //cout << x + dir[i][0] << " "<<y + dir[i][1]<<endl;
    }
    dp[1][1] = 1;
    for(int i = 1;i<=n + 1;i++) {
        for(int j = 1;j<=m + 1;j++) {
            if((i == 1 && j == 1) || deny[i][j]) {continue;}
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            //cout << dp[i][j] << " ";
        }
       // cout << endl;
    }
    cout << dp[n + 1][m + 1];
    return 0;
}