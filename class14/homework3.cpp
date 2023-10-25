#include <iostream>
#include <string>
using namespace std;

struct node {
	char data;
	int l, r;
} tree[1005];
int cnt = 0;
string extract (string n,string s) {
	string ans = "";
	for(int i = 0;i<n.size();i++) {
		if(s.find(n[i]) != string::npos) {
			ans+=n[i];
		}
	}
	return ans;
}

void f(int start,int mode,string s,string s2) {
	if(cnt == 0){
		tree[cnt].data = s2[0];
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		string res1 = s.substr(0, s.find(s2[0]));
		string res2 = extract(s2,res1);
		string res3 = s.substr(res1.size() + 1);
		string res4 = extract(s2,res3);
		int tmp = cnt - 1;
		f(cnt - 1,0,res1,res2);
		f(tmp,1,res3,res4);
		return;
	}
	if(s.size() == 1) {
		tree[cnt].data = s2[0];
		tree[cnt].l = tree[cnt].r = -1;
		cnt++;
		if(mode == 0) {
			tree[start].l = cnt - 1;
		}
		else {
			tree[start].r = cnt - 1;
		}
		return;
	}
	if(mode == 0) {
		tree[cnt].data = s2[0];
		tree[cnt].l = tree[cnt].r = -1;
		tree[start].l = cnt;
		cnt++;
		string res1 = s.substr(0, s.find(s2[0]));
		string res2 = extract(s2,res1);
		string res3 = s.substr(res1.size() + 1);
		string res4 = extract(s2,res3);
		int tmp = cnt - 1;
		f(cnt - 1,0,res1,res2);
		f(tmp,1,res3,res4);
	}
	else {
		tree[cnt].data = s2[0];
		tree[cnt].l = tree[cnt].r = -1;
		tree[start].r = cnt;
		cnt++;
		string res1 = s.substr(0, s.find(s2[0]));
		string res2 = extract(s2,res1);
		string res3 = s.substr(res1.size() + 1);
		string res4 = extract(s2,res3);
		int tmp = cnt - 1;
		f(cnt - 1,0,res1,res2);
		f(tmp,1,res3,res4);
	}
}

void print(int bt) {
	if (bt != -1) {
		cout << tree[bt].data << " ";
		print(tree[bt].l);
		print(tree[bt].r);
	}
}

int main() {
	string s,s1;
	cin>>s>>s1;
	f(0,0,s,s1);
	print(0);
	return 0;
}
