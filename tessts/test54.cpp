#include <iostream>
#include <string>
using namespace std;
string s;int r;

void dfs(string buf,int u,int sindex) {
	if(u == r) {
		cout << buf<<endl;
	}
	for(int i = sindex;i<s.size();i++) {
		dfs(buf+s[i],u+1,i+1);
	}
}

int main() {
	cin>>s>>r;
	dfs("",0,0);
	return 0;
}
