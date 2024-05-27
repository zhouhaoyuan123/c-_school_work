#include <iostream>
#include <algorithm>
using namespace std;
struct number {
	int id;
	long long num;
};
number num[1000005];
bool cmp(number x,number y) {
	if(x.num == y.num) {
		return x.id < y.id;
	}
	return x.num < y.num;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i].num;
		num[i].id = i;
	}
	sort(num+1,num+1+n,cmp);
	long long ans = 0;
	for(int i = 1,j = n;j - i > 0;i++,j --) {
		ans += ((num[i].num + num[j].num) / 2 - num[i].num)*min(abs(num[i].id - num[j].id),n - abs(num[i].id - num[j].id));
	}
	cout << ans;
	return 0;
}
