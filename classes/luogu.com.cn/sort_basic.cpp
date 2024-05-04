#include <iostream>
#include <algorithm>
using namespace std;
long long num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	for(int i = 1;i<=n;i++){
		cout << num[i]<<" ";
	}
	return 0;
}
