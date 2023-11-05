#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int main() {
//	freopen("elevator.in" , "r" , stdin);
//	freopen("elevator.out","w",stdout);
	long long n,total = 0;
	cin>>n;
	//map<long long,int> m;
	long long floor[n];
	long long max = 0;
	for(int i = 0;i<n;i++) {
		cin>>floor[i];
		if(floor[i] > max) {
			max = floor[i];
		}
	}
	sort(floor,floor+n);
	int t = 0;
	for(long long i = 1;i<=max;i++) {
		if(floor[t] != i) {
			total += 5 * (floor[t] - i);
			i += floor[t] - i - 1;
			continue;
		}
		total += 5 + 3;
		while(t < n && floor[t] == i) {
			total += 2;
			t++;
		}
		//cout << total << " "<<t << endl;
	}
	total += max * 4;
	cout << total;
	return 0;
}
