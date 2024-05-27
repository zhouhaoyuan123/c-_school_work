#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct island {
    int l,r;
}islands[1005];
bool cmp(island x,island y) {
    if(x.r == y.r) {
        return x.l < y.l;
    }
    return x.r < y.r;
}
int main() {
    int n,d;
    cin>>n>>d;
    for(int i = 1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        double dis = sqrt(1.0 * d * d - abs(y) * abs(y));
        if(1.0 * d * d - abs(y) * abs(y) < 0) {
            cout << -1;
            return 0;
        }
        dis = int(dis);
        islands[i].l = x - dis;
        islands[i].r = x + dis;
    }
    sort(islands+1,islands + 1 + n,cmp);
    int last = 0;
    int cnt = 0;
    for(int i = 1;i<=n;i++) {
        if(i == 1) {
            cnt++;
            last = 1;
        }
        else {
            if(islands[last].r < islands[i].l) {
                cnt++;
                last = i;
            }
        }
    }
    cout << cnt;
    return 0;
}