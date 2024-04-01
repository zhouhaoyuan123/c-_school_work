#include <iostream>
using namespace std;
int matrix[105][105];

int main() {
	int n,m,t;
	cin>>n>>m>>t;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin>>matrix[i][j];
		}
	}
	if(t == 90) {
		for(int i = 1;i<=m;i++) {
			for(int j = n;j>=1;j--) {
				cout<<matrix[j][i]<<" ";
			}
			cout << endl;
		}
	}
	else if (t == 180) {
		for(int i = n;i>=1;i--) {
			for(int j = m;j>=1;j--) {
				cout<<matrix[i][j]<<" ";
			}
			cout << endl;
		}
	}
	else {
		for(int i = m;i>=1;i--) {
			for(int j = 1;j<=n;j++) {
				cout<<matrix[j][i]<<" ";
			}
			cout << endl;
		}
	}
	return 0;
}
