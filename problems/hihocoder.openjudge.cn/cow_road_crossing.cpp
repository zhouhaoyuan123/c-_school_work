#include <iostream>
using namespace std;
int n;
int num[500005];
int num2[500005];
int dict[500005];
int res[500005];
long long ans = 0;
void calc(int num[], int s,int t) {
	if(s == t) {
		return;
	}
	int mid = (s + t) / 2;
	calc(num,s,mid);
	calc(num,mid + 1,t);
	int cnt1 = s,cnt2 = mid + 1;
	int cnt3 = s;
	while(cnt1 <= mid || cnt2 <= t) {
		int tmp2 = 1e9 + 10;
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
		dict[num[i]] = i;
	}
	for(int i = 1;i<=n;i++) {
		cin>>num2[i];
		num2[i] = dict[num2[i]];
		num[i] = num2[i];
	}
	calc(num,1,n);
	long long finalans = 1e11; 
	for(int i = n;i>=1;i--) {
		ans -= (n - num2[i]);
		ans += (num2[i] - 1);
		finalans = min(finalans,ans);
	}
	cout << finalans << endl;
	return 0;
}
