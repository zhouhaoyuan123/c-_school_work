#include <iostream>
using namespace std;
int num[1005];

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>num[i];
	}
	int cnt = n - 1;
	for(int i = 0;i<n;i++) {
		bool flag = 0;
		for(int j = 1;j<=cnt;j++) {
			if(num[j - 1] > num[j]) {
				flag = 1;
				int tmp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = tmp;
			}
		}
		if(!flag) {
			break;
		}
		cnt --;
	}
	for(int i = 0;i<n;i++) {
		cout << num[i]<<" ";
	}
	return 0;
}
