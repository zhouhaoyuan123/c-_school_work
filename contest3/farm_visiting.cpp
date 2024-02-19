#include <iostream>
#include <algorithm>
using namespace std;

int limit[2 * 100000 + 5];
int plan[2 * 100000 + 5];
int gap[2 * 100000 + 5];

int main() {
	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++) {
		cin>>limit[i];
	}
	for(int i = 0;i<n;i++) {
		cin>>plan[i];
		gap[i] = limit[i] - plan[i];
	}
	sort(gap,gap+n,greater<int>());
	while(q--) {
		int V,S;
		cin>>V>>S;
		if(gap[V - 1] - S > 0) {
			cout << "YES"<<endl;
		}
		else {
			cout << "NO"<<endl;
		}
	}
	return 0;
}
