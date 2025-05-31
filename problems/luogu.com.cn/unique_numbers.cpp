#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int,bool> num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t --) {
		int n;
		cin>>n;
		num.clear();
		for(int i = 1;i<=n;i++) {
			int x;
			cin>>x;
			if(!num.count(x)) {
				num[x] = true;
				cout << x << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
