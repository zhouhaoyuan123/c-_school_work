#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long stones[50005];

struct line {
	long long l,r,f,e,id;
	friend bool operator < (const line x,const line y) {
		return stones[x.r] - stones[x.l] > stones[y.r] - stones[y.l];	
	}
};
int order[50005];
line gap[50005];
priority_queue<line> q;

int main() {
	int l,n,m;
	cin>>l>>n>>m;
	stones[0] = 1,stones[n + 1] = 1 + l;
	for(int i = 1;i<=n + 1;i++) {
		gap[i].id = i;
		if(i == n + 1) {
			gap[i].l = i - 1,gap[i].r = i;
			q.push(gap[i]);
			gap[i].l = i - 1,gap[i].r = i;
			gap[i].f = i - 1,gap[i].e = i+1;
			continue;
		}
		cin>>stones[i];
		gap[i].l = i - 1,gap[i].r = i;
		gap[i].f = i - 1,gap[i].e = i+1;
		q.push(gap[i]);
	}
	//sort(gap+1,gap+1+n,cmp);

	while(m -- ) {
		line now = q.top();
		q.pop();
		if(gap[now.id].f == 0 && gap[now.id].e == 0) {m++;continue;}
		//cout << (stones[now.r] - stones[now.l - 1]) << " " << (stones[now.r + 1] - stones[now.l])<<endl;
		if((now.l != 0 || now.f == -1)&& (stones[now.r] - stones[gap[now.f].l]) <= (stones[gap[now.e].r] - stones[now.l]) ) {
			//stones[now.l] = stones[now.l - 1];
			int tmp = now.f;
			now.l = gap[now.f].l;
			now.f = gap[now.f].f;
			gap[now.f].e = now.id;
			gap[tmp].f = 0;
			gap[tmp].e = 0;
		}
		else if(now.r != n+1 || now.e == n + 2) {
			int tmp = now.e;
			now.r = gap[now.e].r;
			now.e =	gap[now.e].e;
			gap[now.e].f = now.id;
			gap[tmp].f = 0;
			gap[tmp].e = 0;
		}
		else {
			int tmp = now.f;
			now.l = gap[now.f].l;
			now.f = gap[now.f].f;
			gap[now.f].e = now.id;
			gap[tmp].f = 0;
			gap[tmp].e = 0;
		}
		q.push(now);
		//cout << now.l <<" "<<now.r<<endl;
	}
	long long minn = 1e9 + 5;
	int length = q.size();
	for(int i = 1;i<=length;i++) {
		if(stones[q.top().r] - stones[q.top().l] == 0 || (gap[q.top().id].f == 0 && gap[q.top().id].e == 0)) {
			q.pop();
			continue;
		}
		minn = min(minn,stones[q.top().r] - stones[q.top().l]);
		q.pop();
	}
	cout << minn;
	return 0;
}
