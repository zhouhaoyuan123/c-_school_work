#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int,int> nodes[50005];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int num[50005];

int main() {
    // freopen("rabbit.in","r",stdin);
    // freopen("rabbit.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
    }
    sort(num+1,num+1+n,greater<int>());
    for(int i = 1;i<=m;i++) {
        int tmp,tmp2;
        cin>>tmp>>tmp2;
        nodes[i] = {tmp,tmp2};
    }
    sort(nodes+1,nodes+1+m,greater<pair<int,int> >());
    long long ans = 0;
    for(int i = 1,j = 1;i<=n&&j<=m;i++) {
        while(j<=m && nodes[j].first >= num[i]) {
            q.push({nodes[j].second,nodes[j].first});
            j++;
        }
        if(q.empty()) {
            cout << "No Solution";
            return 0;
        }
        ans += 1ll * q.top().first;
        q.pop();
    }
    cout << ans;
    return 0;
}