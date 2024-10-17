#include <iostream>
using namespace std;
int fa[150005];
void init(int n) {
    for(int i = 1;i<=n;i++) {
        fa[i] = i;
    }
}
int get(int x) {
    if(fa[x] == x) {
        return x;
    }
    return fa[x] = get(fa[x]);
}
void merge(int x,int y) {
    fa[get(x)] = get(y);
}

int main() {
    int n,k;
    cin>>n>>k;
    init(3 * n);
    int ans = 0;
    for(int i = 1;i<=k;i++) {
        int d,x,y;
        cin>>d>>x>>y;
        if(d == 1) {
            if(x > n || y > n) {
                ans ++;
                continue;
            }
            if(get(y) == get(x) || (get(x) != get(n + y) 
            && get(x) != get(2 * n + y) )) {
                merge(x,y);
                merge(n + x,n + y);
                merge(2 * n + y,2 * n + x);
            }
            else {
                ans ++;
            }
        }
        else {
            if(x > n || y > n || x == y) {
                ans ++;
                continue;
            }
            if((get(y) == get(n + x)) 
            || (get(x) != get(y)) && (get(x) != get(n + y)) && (get(y) != get(2 * n + x))) {
                merge(y,n+x);
                merge(x,2 * n + y);
                merge(2 * n + x,n + y);
            }
            else {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}