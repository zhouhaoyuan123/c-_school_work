#include <iostream>
#include <string>
#include <set>
using namespace std;
string str[105];
set<string> ans;

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>str[i];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(i != j) ans.insert(str[i] + str[j]);
		}
	}
	cout << ans.size() << endl;
	return 0;
}
