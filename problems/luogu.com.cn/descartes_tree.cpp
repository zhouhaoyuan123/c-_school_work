#include <iostream>
#include <stack>
using namespace std;
int tree[10000005][2];
int p[10000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	stack<int> st;
	for(int i = 1;i<=n;i++) {
		cin>>p[i];	
	}
	for(int i = 1;i<=n;i++) {
		int tmp = 0;
		while(!st.empty() && p[st.top()] > p[i]) {
			tmp = st.top();
			st.pop();
		}
		if(!st.empty()) {
			tree[st.top()][1] = i;
		}
		if(tmp != 0) {
			tree[i][0] = tmp;
		}
		st.push(i);
	}
	long long ans1 = 0,ans2 = 0;
	for(int i = 1;i<=n;i++) {
		ans1 ^= 1ll * i * (tree[i][0] + 1);
		ans2 ^= 1ll * i * (tree[i][1] + 1);
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
