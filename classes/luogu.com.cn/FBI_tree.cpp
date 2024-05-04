#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
//string tree[2005];
int vis[2300];
int n;
int maxn = 0;
void build(int index,string s) {
	if(s.size() == 0) {
		return;
	}
	if(s.size() == 1) {
		//tree[index] += s;
		if(s[0] == '0' ) {
			vis[index] = 1;
		}
		else {
			vis[index] = 2;
		}
		maxn = max(maxn,index);
		return;
	}
	build(index * 2 ,s.substr(0,s.size() / 2));
	build(index * 2 + 1,s.substr(s.size() / 2,s.size() / 2));
	if(abs(vis[index * 2] - vis[index * 2 + 1]) == 0) {
		vis[index] = vis[index * 2];
	}
	else {
		vis[index] = 3;
	}
}
void search(int index) {
	if(index > maxn || vis[index] == 0) {
		return;
	}
	search(index * 2);
	search(index * 2 + 1);
	if(vis[index] == 1) {
		cout << 'B';
	}
	else if(vis[index] == 2) {
		cout << 'I';
	}
	else {
		cout << 'F';
	}
}

int main() {
	cin>>n;
	n = pow(2,n);
	string s;
	cin>>s;
	//memset(tree,-1,sizeof(tree));
	build(1,s);
	search(1);
	return 0;
}
