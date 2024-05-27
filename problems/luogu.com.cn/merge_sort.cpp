#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct number {
	int id;
	int num;
}num[500005];
bool vis[500005];
int ans[500005];
//int * merge(int l,int r,int l2,int r2) {
//	int c1,c2;
//	for(c1 = l,c2 = l2;c1 <= r && c2 <= r;) {
//		
//	}
//}
//
//vo merge_sort(int l,int r) {
//	if(l == r) {
//		return;	
//	}
//	merge_sort(l,l+(l+r) / 2);
//	merge_sort(l+(l+r) / 2 + 1,r);
//	
//}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		num[i].id = i;
		cin>>num[i].num;
	}
	
	return 0;
}
