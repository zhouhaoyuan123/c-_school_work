#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
vector<int> G[10005];
map<int,int> dict;
int val[10005];
int ans[10005];
int length[10005];
queue<int> q;

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int id;
		cin>>id;
		dict[id] = i;
		int len;
		cin>>len;
		val[i] = len;
		int tmp;
		cin>>tmp;
		while(tmp != 0) {
			G[dict[tmp]].push_back(i);
			length[i] ++;
			cin>>tmp;
		}
	}
	q.push(1);
	ans[1] = val[1];
	while(!q.empty()) {
		int index = q.front();
		q.pop();
		for(int i = 0;i<G[index].size();i++) {
			length[G[index][i]] --;
			if(length[G[index][i]] <= 0) {
				ans[G[index][i]] = val[G[index][i]] + ans[index];
				q.push(G[index][i]);
			}
		}
	}
	int maxn = 0;
	for(int i = 1;i<=n;i++) {
		maxn = max(maxn,ans[i]);
	}
	cout << maxn << endl;
	return 0;
}
