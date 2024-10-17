#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 200005;
struct Edge {
    int v, next,d;
} e[MAX_M];
int p[MAX_N], eid;
int fa[MAX_N];
int g[MAX_N][20];
int get(int x) {
    if(fa[x] == x) {
        return x;
    }
    return fa[x] = get(fa[x]);
}
priority_queue<pair<int,pair<int,int> > > lines;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v,int d) {
    e[eid].v = v;
    e[eid].next = p[u];
    e[eid].d = d;
    p[u] = eid++;
}
int f[MAX_N][20], d[MAX_N];
void dfs(int u) {
    d[u] = d[f[u][0]] + 1;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == f[u][0]) {
            continue;
        }
        f[v][0] = u;
        g[v][0] = e[i].d;
        dfs(v);
    }
}
int lca(int x,int y) {
    int res = 1e7;
    if(d[x] < d[y]) {
        swap(x,y);
    }
    int K = 0;
    while ((1 << (K + 1)) <= d[x]) {
        K++;
    }
    for(int j = K;j>=0;j--) {
        if(d[f[x][j]] >= d[y]) {
            res = min(res,g[x][j]);
            x = f[x][j];
        }
    }
    if(x == y) {
        return res;
    }
    for(int j = K;j>=0;j--) {
        if(f[x][j] != f[y][j]) {
            res = min(res,min(g[x][j],g[y][j]));
            x = f[x][j];
            y = f[y][j];
        }
    }
    return min(res,min(g[x][0],g[y][0]));
}
int main() {
    int n, q;
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v,d;
        cin >> u >> v>>d;
        insert(u, v, d);
        insert(v, u, d);
        lines.push({d,{u,v}});
    }
    cin >> q;
    while (q--) {
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i = 1;i<=n;i++) {
            fa[i] = i;
        }
        int x, y;
        cin >> x >> y;
        priority_queue<pair<int,pair<int,int> > > tmp = lines;
        while(!tmp.empty()) {
            pair<int,pair<int,int> > now = tmp.top();
            tmp.pop();
            fa[now.second.second] = fa[now.second.first];
            if(get(x) == get(y)) {
                break;
            }
        }
        if(get(x) != get(y)) {
            cout << -1 << endl;
            continue;
        }
        dfs(get(x));
        for(int j = 1;(1 << j) <= n;j++) {
            for(int i = 1;i<=n;i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
                g[i][j] = min(g[i][j - 1],g[f[i][j - 1]][j - 1]);
            }
        }
        cout << lca(x,y)<<endl;
    }
    return 0;
}