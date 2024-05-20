#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int front[385][2],back[385][2]; 

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans = 0;
	for(int i = n - 1;i>=0;i--) {
		while
	}
	for(int i = n - 1;i>=0;i--) {
		if(s[i] == 'w') {
			front[i][0] = front[(i + 1) % n][0];
			front[i][1] = front[(i + 1) % n][1] + 1;
			continue;
		}
	}
	cout << ans<<endl;
	return 0;
}

