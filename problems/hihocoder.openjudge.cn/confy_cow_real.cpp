#include <iostream>
#include <queue>
using namespace std;
queue <pair<int,int> > q;
bool vis[2025][2025];
int ans = 0;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool check(int x,int y) {
	x += 500;
	y += 500;
	int ans = 0;
	if(-500 <= x - 1 && x - 1 <= 1500 && vis[x - 1][y]) ans ++;
	if(-500 <= x + 1 && x + 1 <= 1500 && vis[x + 1][y]) ans ++;
	if(-500 <= y + 1 && y + 1 <= 1500 && vis[x][y + 1]) ans ++;
	if(-500 <= y - 1 && y - 1 <= 1500 && vis[x][y - 1]) ans ++;
	return (ans == 3);
}
bool inborder(int x,int y) {
	if(-500 <= x && x <= 1500 && -500 <= y && y <= 1500) { 
		return true;
	}
	return false;
}

void add(int x,int y) {
	x += 500;
	y += 500;
	vis[x][y] = 1;
	q.push({x - 500,y - 500});
	ans ++;
	for(int i = 0;i<4;i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(vis[nx][ny]) {
			q.push({nx - 500,ny - 500});
		}
	}
}

void bfs() {
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(check(x,y)) {
			if(inborder(x + 1,y) && !vis[x + 1 + 500][y + 500]) {
				add(x + 1,y);
			}
			else if(inborder(x,y + 1) && !vis[x + 500][y + 1 + 500]) {
				add(x,y + 1);
			}
			else if(inborder(x - 1,y) && !vis[x - 1 + 500][y + 500]) {
				add(x - 1,y);
			}
			else if(inborder(x,y - 1) && !vis[x + 500][y - 1 + 500]) {
				add(x,y - 1);
			}
		}
	}	
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		if(!vis[x + 500][y + 500]) {
			add(x + 500,y + 500);
		}
		bfs();
		cout << ans - i << endl;
	}
	return 0;
}
