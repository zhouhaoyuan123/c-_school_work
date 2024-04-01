#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	cin>>s;
	stack<int> st;
	int buf = 0;
	for(int i = 0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			buf = buf * 10 + s[i] - '0';
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
		else if(s[i] == '.') {
			st.push(buf);
			buf = 0;
		}
	}
	cout << st.top();
	return 0;
}
