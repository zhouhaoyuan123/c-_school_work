#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct pile {
	double value;
	int num;
};
bool cmp(pile x,pile y) {
	return x.value > y.value;
}
pile price[105];

int main() {
	int N;double T;
	cin>>N>>T;
	for(int i = 1;i<=N;i++) {
		int m,v;
		cin>>m>>v;
		price[i].value = 1.0 * v/m;
		price[i].num = m;
	}
	sort(price+1,price+1+N,cmp);
	double ans = 0;
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
	cout << fixed<<setprecision(2)<<ans;
	return 0;
}
