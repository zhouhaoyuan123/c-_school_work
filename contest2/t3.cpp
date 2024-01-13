#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	cin>>n;
	int parent[n+1];
	int points[n+1];
	memset(parent,0,sizeof(parent));
	memset(points,0,sizeof(points));
	parent[1] = 0;
	for(int i = 2;i<=n;i++) {
		cin>>parent[i];
	}
	for(int i = 1;i<=n;i++) {
		points[i] += 1;
		int cur = i;
		int p = 2;
		while(parent[cur] != 0) {
			cur = parent[cur];
			points[cur] += p;
			p++;
		}
	}
	for(int i = 1;i<=n;i++) {
		cout << points[i]<<" ";
	}
	return 0;
}
