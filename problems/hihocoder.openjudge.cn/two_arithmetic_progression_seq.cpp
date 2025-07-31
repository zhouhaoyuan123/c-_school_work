#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int num[500005];
int a[500005],b[500005];
bool suffix[500005];
bool checkpush(int num[],int n,int x) {
	if(n <= 1) return true;
	if(num[2] - num[1] == x - num[n]) {
		return true;
	}
	return false;
}
bool checksuffix(int b[],int cnt,int n,int x) {
	return suffix[x] && (cnt == 0 || x == n || num[x + 1] - num[x] == num[x] - b[cnt]);
}
bool dfs(int x,int cnt1,int cnt2) {
	if(x == n + 1) {
		return true;
	}
	bool pusha = checkpush(a,cnt1,num[x]),pushb = checkpush(b,cnt2,num[x]);
	if(pusha && !pushb) {
		a[cnt1 + 1] = num[x];
		return dfs(x + 1,cnt1 + 1,cnt2);
	}
	else if(!pusha && pushb) {
		b[cnt2 + 1] = num[x];
		return dfs(x + 1,cnt1,cnt2 + 1);
	}
	else if(!pusha && !pushb) return false;
	if(cnt1 < 2 && cnt2 < 2) {
		a[cnt1 + 1] = num[x];
		if(dfs(x + 1,cnt1 + 1,cnt2)) return true;
		b[cnt2 + 1] = num[x];
		if(dfs(x + 1,cnt1,cnt2 + 1)) return true;
		return false;
	}
	if(cnt1 > 2) {
		if(checksuffix(b,cnt2,n,x)) return true;
		a[cnt1 + 1] = num[x];
		if(dfs(x + 1,cnt1 + 1,cnt2)) return true;
		return false;
	}
	if(checksuffix(a,cnt1,n,x)) return true;
	b[cnt2 + 1] = num[x];
	if(dfs(x + 1,cnt1,cnt2 + 1)) return true;
	return false;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		memset(num,0,sizeof(num));
		memset(suffix,0,sizeof(suffix));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i = 1;i<=n;i++) {
			cin>>num[i];
		}
		suffix[n] = true;
		suffix[n - 1] = true;
		for(int i = n - 2;i>=1;i--) {
			if(num[i + 1] - num[i] == num[i + 2] - num[i + 1]) {
				suffix[i] = suffix[i + 1];
			}
			else {
				suffix[i] = false;
			}
		}
		bool flag = dfs(1,0,0);
		if(flag) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	cout << endl;
	return 0;
}
