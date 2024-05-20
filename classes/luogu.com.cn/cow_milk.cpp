#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct pile {
	int value;
	int num;
};
bool cmp(pile x,pile y) {
	return x.value < y.value;
}
pile price[5005];

int main() {
	int N;int T;
	cin>>T>>N;
	for(int i = 1;i<=N;i++) {
		int m,v;
		cin>>m>>v;
		price[i].value = m;
		price[i].num = v;
	}
	sort(price+1,price+1+N,cmp);
	int ans = 0;
	for(int i = 1;i<=N;i++) {
		if(T >= price[i].num) {
			T -= price[i].num;
			ans += (price[i].num*price[i].value);
		}
		else {
			ans += (price[i].value * T);
			break;
		}
	}
	cout << ans;
	return 0;
}
