#include <iostream>
#include <stack>
using namespace std;


int main() {
	stack <int> st;
	int t;
	long long ans = 0;
	while(cin>>t && t != 0) {
		st.push(t);
		ans += t * st.size();
	}
	cout << ans<<endl;
	while(!st.empty()) {
		cout << st.top()<<" ";
		st.pop();
	}
	return 0;
}
