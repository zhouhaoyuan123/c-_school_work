#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct person {
	int num;
	int id;
};
bool cmp(person x,person y) {
	if(x.num == y.num) {
		return x.id < y.id;
	}
	return x.num < y.num;
}
person num[1005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i].num;
		num[i].id = i;
	}
	sort(num+1,num+1+n,cmp);
	double ans = 0;
//	ans -= num[1].num;
	double ans2 = 0;
	for(int i = 1;i<=n;i++) {
		ans += num[i - 1].num;
		ans2 += ans;
		cout << num[i].id << " ";
	}
	cout << endl<<fixed << setprecision(2)<<ans2 / n;
	return 0;
}
