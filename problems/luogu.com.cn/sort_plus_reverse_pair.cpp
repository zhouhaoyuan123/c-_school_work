#include <iostream>
using namespace std;
int n;
long long num[500005];
long long res[500005];
long long ans = 0;
void calc(int s,int t) {
	if(s == t) {
		return;
	}
	int mid = (s + t) / 2;
	calc(s,mid);
	calc(mid + 1,t);
	int cnt1 = s,cnt2 = mid + 1;
	int cnt3 = s;
	while(cnt1 <= mid || cnt2 <= t) {
		long long tmp2 = 1e9 + 10;
		if(cnt1 <= mid) {
			tmp2 = num[cnt1];
		}
		if(cnt2 <= t) {
			tmp2 = min(tmp2,num[cnt2]);
		}
		if(cnt1 <= mid && (tmp2 != num[cnt1] || (cnt2 <= t && num[cnt1] == num[cnt2]))) {
			int tmp3 = cnt1;
			while(tmp3 <= mid && num[tmp3] == tmp2) {
				tmp3 ++;
			}
			ans += mid - tmp3 + 1;
		}
		if(cnt2 <= t && tmp2 == num[cnt2]) {
	 		cnt2 ++;
		}
		else {
			cnt1 ++;
		}
		res[cnt3] = tmp2;
		cnt3 ++;
	}
	for(int i = s;i<=t;i++) {
		num[i] = res[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	calc(1,n);
	cout << ans << endl;
	return 0;
}
