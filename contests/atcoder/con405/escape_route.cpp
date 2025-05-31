#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
queue<pair<int,pair<int,int> > > q;
int h,w;
string maze[1005];
int ans[1005][1005];
int d[1005][1005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char dir_char[4] = {'<','^','>','v'};

int main() {
	cin>>h>>w;
	memset(d,0x3f,sizeof(d));
	for(int i = 1;i<=h;i++) {
		cin>>maze[i];
		for(int j = 0;j<maze[i].size();j++) {
			if(maze[i][j] == 'E') {
				q.push({i,{j+1,0}});
				d[i][j + 1] = 0;
			}
		}
	}
	while(!q.empty()) {
		auto cur = q.front();
		int x = cur.first;
		int y = cur.second.first;
		int step = cur.second.second;
		q.pop();
		if(d[x][y] < step) continue;	
		for(int i = 0;i<4;i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(1 <= nx && nx <= h && 1 <= ny && ny <= w && d[nx][ny] > step + 1 && maze[nx][ny - 1] != '#') {
				d[nx][ny] = step + 1;
				ans[nx][ny] = i;
				q.push({nx,{ny,step+1}});
			}
		}
	}
	for(int i = 1;i<=h;i++) {
		for(int j = 1;j<=w;j++) {
			if(maze[i][j - 1] == '#' || maze[i][j - 1] == 'E') {
				cout << maze[i][j - 1];
			}
			else {
				cout << dir_char[ans[i][j]];
			}
		}
		cout << endl;
	}
	return 0;
}
