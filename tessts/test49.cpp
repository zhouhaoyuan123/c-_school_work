#include <bits/stdc++.h>
using namespace std;
string a,b;
bool in(string s) {
	int tmp0 = s[0] - '0' - 1,tmp1 = s[0] - '0' + 1;
	if(tmp0 < 1) {
		tmp0 = 9;
	}
	if(tmp1 > 9) {
		tmp0 = 1;
	}
	return tmp0 == s[3] - '0' || tmp1 == s[3] - '0';
}
int dir[3][2] {
{1,0},{0,1},{0,-1}
};
struct node {
	string s;int d;
	node(string _s,int _d) {
		s = _s;
		d =_d;
	}
	bool operator < (const node other) const {
		if(s == other.s) {
			return d < other.d;
		}
		return s < other.s;
	}
};
set<node> vis;
int bfs(string start) {
	queue<node> q;
	q.push(node(start,0));
	vis.insert(q.front());
	while(!q.empty()) {
		node now = q.front();
		if(now.s == b) {return now.d;}
		q.pop();
		for(int i = 0;i<4;i++) {
			for(int j = 0;j<3;j++) {
				if(dir[j][0] == 1 && i < 3) { 
					node tmp = now;
					swap(tmp.s[i],tmp.s[i + 1]);
					if(!in(tmp.s) && !vis.count(tmp)) {
						vis.insert(tmp);
						q.push(node(tmp.s,now.d + 1));
					}
				}
				else {
					node tmp = now;tmp.s[i] += dir[j][1];
					if(tmp.s[i] > '9') {
						tmp.s[i] = '1';
					}
					if(tmp.s[i] < '1') tmp.s[i] = '9';
					if(!in(tmp.s) && !vis.count(tmp)) {
						vis.insert(tmp);
						q.push(node(tmp.s,now.d + 1));
					}
				}
			}
		}
	}
	return -1;
}
int main() {
//	freopen("lock.in","r",stdin);
//	freopen("lock.out","w",stdout);
	cin>>a>>b;
	cout << bfs(a);
	return 0;
}
