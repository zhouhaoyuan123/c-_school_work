#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct person {
	int id;
	int duration;
}people[1005];
bool cmp(person x,person y) {
	return x.duration < y.duration;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>people[i].duration;
		people[i].id = i;
	}
	sort(people + 1,people + 1 + n,cmp);
	long long ans = 0,cnt = 0;
	for(int i = 1;i<=n;i++) {
		cout << people[i].id << " ";
		ans += cnt;
		cnt += people[i].duration;
	}
	cout << endl;
	cout << fixed << setprecision(2) << 1.0 * ans / n << endl;
	return 0;
}
