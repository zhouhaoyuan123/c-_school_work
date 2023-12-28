#include <bits/stdc++.h>
using namespace std;
string a,b;
bool in(string s) {
	int tmp0 = s[0] - '0' - 1,tmp1 = s[0] - '0' + 1;
//	if(tmp0 < 1) {
//		tmp0 = 9;
//	}
//	if(tmp1 > 9) {
//		tmp0 = 1;
//	}
	return s == b || tmp0 == s[3] - '0' || tmp1 == s[3] - '0';
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
		return s < other.s;
	}
};
set<string> vis;
int bfs(string start) {
	queue<node> q;
	q.push(node(start,0));
	vis.insert(a);
	while(!q.empty()) {
		node now = q.front();
		if(now.s == "5876") cout << "ok" << endl;
		if(now.s == b) {return now.d;}
		q.pop();
		for(int i = 0;i<4;i++) {
			for(int j = 0;j<3;j++) {
				if(dir[j][0] == 1 && i < 3) { 
					node tmp = now;
					swap(tmp.s[i],tmp.s[i + 1]);
					if(!in(tmp.s) && !vis.count(tmp.s)) {
						vis.insert(tmp.s);
						q.push(node(tmp.s,now.d + 1));
					}
				}
				else {
					node tmp = now;
					tmp.s[i] = tmp.s[i] - '0' + dir[j][1] + '0';
					if(tmp.s[i] > '9') {
						tmp.s[i] = '1';
					}
					if(tmp.s[i] < '1') tmp.s[i] = '9';
					if(!in(tmp.s) && !vis.count(tmp.s)) {
						vis.insert(tmp.s);
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
