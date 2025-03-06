#include <iostream>
#include <algorithm>
using namespace std;
int num[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num + 1,num + 1 + n);
	n = unique(num + 1,num + 1 + n) - num - 1;
	cout << n << endl;
	for(int i = 1;i<=n;i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	return 0;	
}
