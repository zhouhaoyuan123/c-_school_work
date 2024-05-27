#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		stack<string> st;
		while(n--) {
			string op;
			cin>>op;
			if(op == "push") {
				string x;
				cin>>x;
				st.push(x);
			}
			else if(op == "pop") {
				if(st.size() == 0) {
					cout << "Empty"<<endl;
				}
				else {
					st.pop();
				}
			}
			else if(op == "query") {
				if(st.size() == 0) {
					cout << "Anguei!"<<endl;
				}
				else {
					cout << st.top()<<endl;
				}
			}
			else {
				cout << st.size()<<endl;
			}
		}
	}
	return 0;
}
