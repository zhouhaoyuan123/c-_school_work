#include <iostream>
#include <queue>
using namespace std;
char maze[1005][1005];
bool vis[1005][1005];
struct point{
	int x,y;
	int step;
};
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>maze[i][j];
		}
	}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	queue<point> q;
	q.push({x1,y1,0});
	while(!q.empty()) {
		point now = q.front();
		q.pop();
		if(now.x == x2 && now.y == y2) {
			cout << now.step;
			return 0;
		}
		for(int i = 0;i<4;i++) {
			int tx = now.x + dir[i][0],ty = now.y + dir[i][1];
			if(1<=tx && tx <= n && 1<=ty && ty <= n && !vis[tx][ty] && maze[tx][ty] == '0') {
				vis[tx][ty] = 1;
				q.push({tx,ty,now.step + 1});
			}
		}
	}
	return 0;
}
