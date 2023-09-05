#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[101];
	for(int i = 0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int x;
	cin>>x;
	int front = lower_bound(a,a+n,x) - a;
	int back = upper_bound(a,a+n,x) - a;
	if(upper_bound(a,a+n,x) == a+n) {
		back = n;
	}
	cout << front+1<<" "<<back;
	return 0;
}
