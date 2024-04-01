#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		stack <int> st;
		int in_order[n];
		int out_order[n];
		for(int i = 0;i<n;i++) {
			cin>>in_order[i];
		}
		for(int i = 0;i<n;i++) {
			cin>>out_order[i];
		}
		int j = 0;
		bool flag = 1;
		for(int i = 0;i<=n;i++) {
			if(!st.empty() && out_order[j] == st.top()) {
				if(i == n) {
					flag = 0;
				}
				j++;
				i--;
				st.pop();
			}
			else if(flag) {
				st.push(in_order[i]);
			}
		}
		if(j == n) {
			cout << "Yes"<<endl;
		}
		else {
			cout << "No"<<endl;
		}
	}
	
	return 0;
}
