#include <iostream>
using namespace std;
int dis[55];

int main() {
	int n;
	cin>>n;
	for(int i = 2;i<=n;i++) {
		cin>>dis[i];
		dis[i] += dis[i - 1];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = i + 1;j<=n;j++) {
			cout << dis[j] - dis[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
