#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    freopen("differrence.in","r",stdin);
    int n,m,changes,gap;
    cin>>n>>m>>changes>>gap;
    int org_change = changes;
    int pics[n][m];
    memset(pics,0,sizeof(pics));
    srand(time(NULL));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            pics[i][j] = (rand() + 1) % 100;
            cout << pics[i][j]<<" ";           
        }    
        cout << endl;
    }    
    cout << "-----------------"<<endl;
    int cnt[changes][2];
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if( (rand() % 2 == 1 && changes > 0) || (changes > 0 && i == n - 1 && j == m - 1 - changes)) {
                int change_num = abs(rand() + pics[i][j] - gap) % (pics[i][j] + gap);
                if(change_num == pics[i][j]) {
                    change_num++;
                }
                changes--;
                cout << change_num <<" ";
                cnt[org_change - changes - 1][0] = i;
                cnt[org_change - changes - 1][1] = j;           
            }
            else {
                cout << pics[i][j]<<" ";
            } 
        }    
        cout << endl;
    }
    cout << "Answers are below-----------"<<endl;
    for(int i = 0;i<org_change;i++) {
        cout << cnt[i][0] + 1<<" "<<cnt[i][1] + 1<<endl;    
    }
    cout << "END Will close in 20 sec."<<endl;
    system("sleep 20");
    return 0;
}
