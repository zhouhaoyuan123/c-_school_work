#include <iostream>
#include <stack>
using namespace std;
long long num[200005];
stack<int> st;
int l[200005],r[200005];
long long ans[200005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i = 1;i<=n;i++) {
		while(!st.empty() && num[st.top()] < num[i]) {
			r[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = n;i>=1;i--) {
		while(!st.empty() && num[st.top()] <= num[i]) {
			l[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j <= r[i] - 1 - l[i];j++) {
			//min(i,n - j + 1) - min(i - j + 1,1) + 1
			ans[j] += 1ll * (min(i,r[i] - j) - max(i - j + 1,l[i] + 1) + 1) * num[i];
		}
	}
	for(int i = 1;i<=n;i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
