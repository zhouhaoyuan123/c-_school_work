#include <iostream>
#include <queue>
using namespace std;
int wet[500005];
long long cnt = 0;
priority_queue<int,vector<int>,less<int> > q;

int main() {
	int n,a,b;
	cin>>n>>a>>b;
	for(int i = 1;i<=n;i++) {
		cin>>wet[i];
		q.push(wet[i]);
	}
	while(true) {
		int first = q.top();
		q.pop();
		if(first - cnt * a <= 0) break;
		q.push(first - b);
		cnt++;
	}
	cout << cnt;
	return 0;
}
