#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

struct node {
    int v,w;
};
vector<node> G[2505];
set<pair<int,int> > heap;
long long d[2505];
void calc(int s) {
    memset(d,0x3f,sizeof(d));
    d[s] = 0;
    heap.insert({0,s});
    while(heap.size()) {
        int dis = heap.begin() -> first;
        int id = heap.begin() -> second;
        for(int i = 0;i<G[id].size();i++) {
            if(d[G[id][i].v] > dis + G[id][i].w) {
                heap.erase({d[G[id][i].v],G[id][i].v});
                d[G[id][i].v] = dis + G[id][i].w;
                heap.insert({d[G[id][i].v],G[id][i].v});
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    calc(1);
    if(d[n] >= 0x3f3f3f3f) {
        cout << -1 << endl;
    }
    else {
        cout << d[n]<<endl;
    }
    return 0;
}