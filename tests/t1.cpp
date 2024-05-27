#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n;
int tree[35][2];
int back[35],middle[35];
int search(int dict[],int l,int r,int target) {
    for(int i = l;i<=r;i++) {
        if(dict[i] == target) {
            return i;
        }
    }
    return -1;
}
void dfs(int parent,int bl,int br,int l,int r,bool flag) {
    if(l > r) return;
    if(l == r) {
        tree[back[parent]][flag] = middle[l];
        return;
    }
    dfs(br,bl,search(middle,l,r,back[r]) - 1,l,search(middle,l,r,back[r]) - 1,0);
    dfs(br,search(middle,l,r,back[r]),br - 1,search(middle,l,r,back[r]) + 1,r,1);
}
int main() {
    // freopen("sort.in","r",stdin);
    // freopen("sort.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        int tmp;
        cin>>tmp;
        back[i] = tmp;
    }
    for(int i = 1;i<=n;i++) {
        int tmp;
        cin>>tmp;
        middle[i] = tmp;
    }
    if(n != 1) {
        dfs(n,1,n,1,n,0);
    }
    for(int i = 1;i<=n;i++) {
        cout << tree[i][0] << " "<<tree[i][1]<<endl;
    }
    return 0;
}