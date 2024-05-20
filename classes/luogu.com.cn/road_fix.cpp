#include <iostream>
using namespace std;
int road[100005];
int num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>road[i];
	}
	for(int i = 1;i<=n;i++) {
		if(road[i] > 0) {
			if(road[i - 1] >= road[i]) {
				num[i] = num[i - 1];
			}
			else {
				num[i] = num[i - 1] + road[i] - road[i - 1];
			}
		}
		else {
			num[i] = num[i - 1];
		}
	}
	cout << num[n];
	return 0;
}
