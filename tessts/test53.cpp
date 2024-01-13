#include <iostream>
using namespace std;
int dotnum[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			int tmp;
			cin>>tmp;
			if(tmp == 1) {
				dotnum[i] ++;
			}
		}
	}
	int m;
	cin>>m;
	for(int i = 1;i<=n;i++) {
		if(dotnum[i] == m) {
			cout << i << endl;
		}
	}
	return 0;
}
