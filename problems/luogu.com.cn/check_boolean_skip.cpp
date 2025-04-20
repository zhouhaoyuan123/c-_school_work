#include <iostream>
#include <stack>
using namespace std;
struct node {
	bool res;
	int a,b;
	char op;
};
struct node2 {
	bool res;
	int id;
};
node tree[1000005];
int cnt = 0;
int ans = 0,ans2 = 0;
bool dfs(int u) {
	if(tree[u].a == 0 || tree[u].b == 0) {
		return tree[u].res;
	}
	if(tree[u].op == '&') {
		if(dfs(tree[u].a) == 0) {
			ans ++;
			return 0;
		}
		else {
			return dfs(tree[u].b);
		}
	}
	else {
		if(dfs(tree[u].a) == 1) {
			ans2 ++;
			return 1;
		}	
		else {
			return dfs(tree[u].b);
		}
	}
}

int main() {
	string s;
	cin>>s;
	s.insert(0,1,'(');
	s += ")";
	stack<node2> nums;
	stack<char> op;
	for(int i = 0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '1') {
			nums.push({s[i] - '0',++cnt});
			tree[cnt].res = s[i] - '0';
			tree[cnt].a = 0;
			tree[cnt].b = 0;
		}
		else if(s[i] == '(') {
			op.push(s[i]);
		}
		else if(s[i] == ')') {
			while(nums.size() > 1 && op.size() && op.top() != '(') {
				bool a = nums.top().res;
				int numa = nums.top().id;
				nums.pop();
				bool b = nums.top().res;
				int numb = nums.top().id;
				nums.pop();
				if(op.top() == '&') {
					nums.push({a & b,++cnt});
					tree[cnt].res = a & b;
					tree[cnt].a = numb;
					tree[cnt].b = numa;
					tree[cnt].op = '&';
				}
				if(op.top() == '|') {
					nums.push({a | b,++cnt});
					tree[cnt].res = a | b;
					tree[cnt].a = numb;
					tree[cnt].b = numa;
					tree[cnt].op = '|';
				}
				op.pop();
			}
			op.pop();
		}
		else {
			while(nums.size() > 1 && op.size() > 0 && op.top() <= s[i] && op.top() != '(') {
				bool a = nums.top().res;
				int numa = nums.top().id;
				nums.pop();
				bool b = nums.top().res;
				int numb = nums.top().id;
				nums.pop();
				if(op.top() == '&') {
					nums.push({a & b,++cnt});
					tree[cnt].res = a & b;
					tree[cnt].a = numb;
					tree[cnt].b = numa;
					tree[cnt].op = '&';
				}
				if(op.top() == '|') {
					nums.push({a | b,++cnt});
					tree[cnt].res = a | b;
					tree[cnt].a = numb;
					tree[cnt].b = numa;
					tree[cnt].op = '|';
				}
				op.pop();
			}
			op.push(s[i]);
		}
	}
	cout << dfs(cnt) << endl;
	cout << ans << " " << ans2 << endl;
	return 0;
}
