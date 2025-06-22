#include <iostream>
using namespace std;
int num[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		num[x] ++;
	}
	int cnt = 0;
	for(int i = 1;i<=100;i++) {
		if(num[i]) {
			cnt ++;
		}
	}
	cout << cnt << endl;
	for(int i = 1;i<=100;i++) {
		if(num[i]) {
			cout << i << " "; 
		}
	}
	cout << endl;
	return 0;
}
