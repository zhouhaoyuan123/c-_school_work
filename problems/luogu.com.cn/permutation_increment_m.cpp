#include <iostream>
#include <algorithm>
using namespace std;
int num[10005];

int main() {
	int n;
	int m;
	cin >>n>>m;
	for(int i = 1;i<=n;i++) {
		cin >> num[i];
	}
	while(m --) {
		next_permutation(num+1,num+1+n);
	}
	for(int i = 1;i<=n;i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	return 0;
}
