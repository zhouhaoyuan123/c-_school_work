#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
int n;
int value[100005];
int tree[1100005][5];
bool important[100005];
int root,cnt;
bool res;
struct num {
	bool val;
	int id;
	char op;
};
void dfs(int u) {
	if(u == 0) return ;
	bool a = tree[u][3],b = tree[u][4];
	if(!tree[u][0] && !tree[u][1]) {
		important[u] = 1;
	}
	if(tree[u][2] == '&' && a == 0 && b == 1) {
		dfs(tree[u][0]);
	}
	if(tree[u][2] == '&' && b == 0 && a == 1) {
		dfs(tree[u][1]);
	}
	if(tree[u][2] == '&' && b == 1 && a == 1) {
		dfs(tree[u][1]);
		dfs(tree[u][0]);
	}
	if(tree[u][2] == '|' && a == 0 && b == 1) {
		dfs(tree[u][1]);
	}
	if(tree[u][2] == '|' && b == 0 && a == 1) {
		dfs(tree[u][0]);
	}
	if(tree[u][2] == '|' && b == 0 && a == 0) {
		dfs(tree[u][0]);
		dfs(tree[u][1]);
	}
	if(tree[u][2] == '!') {
		dfs(tree[u][0]);
	}
}


int main() {
	getline(cin,s);
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>value[i];
		++cnt;
	}
	stack<num> st;
	for(int i = 0;i<s.size();i++) {
		if(s[i] == ' ') {
			continue;
		}
		num tmp;
		if(s[i] == 'x') {
			tmp.id = 0;
			i++;
			while(i < s.size() && s[i] != ' ') {
				tmp.id *= 10;
				tmp.id += (s[i] - '0');
				i++;
			}
			tmp.val = value[tmp.id];
			st.push(tmp);
		}
		else {
			if(s[i] == '&') {
				num a = st.top();
				st.pop();
				num b = st.top();
				st.pop();
				num tmp;
				tmp.val = a.val & b.val;
				tmp.id = ++cnt;
				tmp.op = '&';
				st.push(tmp);
				tree[cnt][0] = a.id;
				tree[cnt][1] = b.id;
				tree[cnt][2] = '&';
				tree[cnt][3] = a.val;
				tree[cnt][4] = b.val;
			}
			if(s[i] == '|') {
				num a = st.top();
				st.pop();
				num b = st.top();
				st.pop();
				num tmp;
				tmp.val = a.val | b.val;
				tmp.id = ++cnt;
				tmp.op = '|';
				st.push(tmp);
				tree[cnt][0] = a.id;
				tree[cnt][1] = b.id;
				tree[cnt][2] = '|';
				tree[cnt][3] = a.val;
				tree[cnt][4] = b.val;
			}
			if(s[i] == '!') {
				num a = st.top();
				st.pop();
				num tmp;
				tmp.val = ! a.val;
				tmp.id = ++cnt;
				tmp.op = '!';
				st.push(tmp);
				tree[cnt][0] = a.id;
				tree[cnt][2] = '!';
				tree[cnt][3] = a.val;
			}
		}
	}
	root = cnt;
	dfs(root);
	int q;
	cin>>q;
	while(q --) {
		int x;
		cin>>x;
		cout << (bool(st.top().val) ^ bool(important[x])) << endl;
	}
	return 0;
}
