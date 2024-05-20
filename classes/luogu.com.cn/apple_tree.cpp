#include <iostream>
#include <algorithm>
using namespace std;
struct apple {
	int x,y;
}tree[5005];
bool cmp(apple x,apple y) {
	if(x.y == y.y) {
		return x.x < y.x;
	}
	return x.y < y.y;
}

int main() {
	int n;
	cin>>n;
	int a,b,s;
	cin>>s>>a>>b;
	for(int i = 1;i<=n;i++) {
		cin>>tree[i].x >> tree[i].y;
	}
	sort(tree+1,tree+1+n,cmp);
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		if(tree[i].x > a+b) {
			continue;
		}
		else if(s >= tree[i].y) {
			ans++;
			s-=tree[i].y;
		}
	}
	cout << ans;
	return 0;
}
