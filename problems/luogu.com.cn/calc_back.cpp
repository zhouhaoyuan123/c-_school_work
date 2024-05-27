#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	cin>>s;
	stack<int> st;
	for(int i = 0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
		}
		else if(s[i] == '*') {
			int fir = st.top();
			st.pop();
			int sec = st.top();
			st.pop();
			st.push(fir * sec);
		}
		else if(s[i] == '/') {
			int fir = st.top();
			st.pop();
			int sec = st.top();
			st.pop();
			st.push(sec/fir);
		}
		else if(s[i] == '+') {
			int fir = st.top();
			st.pop();
			int sec = st.top();
			st.pop();
			st.push(sec + fir);
		}
		else if(s[i] == '-') {
			int fir = st.top();
			st.pop();
			int sec = st.top();
			st.pop();
			st.push(sec - fir);
		}
	}
	cout << st.top();
	return 0;
}
