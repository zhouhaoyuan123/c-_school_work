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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    while(cin>>a>>b) {
        if(a == -1 || b == -1) {
            return 0;
        }
        int n = 0;
        init(10000);
        bool run = 1;
        int cnt = 0;
        while(a != 0 && b != 0) {
            n = max(n,a);
            n = max(n,b);
            cnt ++;
            if(get(a) == get(b)) {
                cout << 0 << endl;
                run = 0;
            }
            merge(a,b);
            cin>>a>>b;
        }
        if(run) {
            int cnt2 = 0;
            for(int i = 1;i<=n;i++) {
                if(fa[i] == i) {
                    cnt2 ++;
                }
            }
            if(cnt2 == 1) {
                cout << 1 << endl;
            }
            else { 
                cout << 0 << endl;
            }
        }
    }
    return 0;
}