#include <iostream>
#include <string>
using namespace std;
int cnt[500005];
int dis(int x,int y) {
	if(x >= y) {
		return x - y;
	}
	else {
		return (10 - y) + x;
	}
}

int main() {
	string num;
	cin>>num;
	long long ans = 0;
	cnt[num.size() - 1] = num[num.size() - 1] - '0';
	for(int i = num.size() - 1;i>=0;i--) {
		ans += dis(num[i] - '0',ans % 10);
	}
	cout << ans + num.size() << endl;
	return 0;
}
