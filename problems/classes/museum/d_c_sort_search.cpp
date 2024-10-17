#include <iostream>
#include <algorithm>
using namespace std;
struct number {
	int id;
	int num;
	bool operator < (const number y) const {
		if(num < y.num) {
			return id < y.id;
		}
		return num < y.num;
	}
};
number num[300005];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	int t;
	cin>>n;
	cin>>t;
	for(int i = 1;i<=n;i++) {
		cin>>num[i].num;
		num[i].id = i;
	}
	//sort(num+1,num+1+n);
	for(int i = 1;i<=t;i++) {
		int target;
		cin>>target;
		int l = 1,r = n;
		int k = -1;
		while(l <= r) {
			int mid = l + r >> 1;
			if(num[mid].num < target) {
				l = mid + 1;
			}
			else if(num[mid].num > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
				k = mid;
			}
		}
		cout << k<<" ";
	}
	return 0;
}
