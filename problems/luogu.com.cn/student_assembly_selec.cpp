#include <iostream>
#include <algorithm>
using namespace std;
int num[2000005];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+m);
	for(int i = 1;i<=m;i++) {
		cout << num[i]<<" ";
	}
	return 0;
}
