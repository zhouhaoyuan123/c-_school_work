#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string dict[100005];
string input[15];
int n,k,x;
int cnt = 0;
void dfs(int i,string cur) {
	if(i - 1 >= k) {
		dict[++cnt] = cur;
		return;
	}
	for(int j = 1;j<=n;j++) {
		dfs(i + 1,cur + input[j]);
	}
}

int main() {
	cin>>n>>k>>x;
	for(int i = 1;i<=n;i++) {
		cin>>input[i];
	}
	dfs(1,"");
	sort(dict+1,dict+1+cnt);
	cout << dict[x] << endl;
	return 0;
}
