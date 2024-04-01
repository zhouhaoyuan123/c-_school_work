#include <iostream>
#include <string>
using namespace std;
const int maxn = 500;
int ans[maxn + 5],a[maxn+5],b[maxn + 5];

void plus_num(int a[],int b[],int ans[]) {
	for(int i = 0;i<maxn;i++) {
		ans[i] += a[i] + b[i];
		if(ans[i] > 9) {
			ans[i+1] ++;
			ans[i] -= 10;
		}
	}	
}

int main() {
	string s1,s2;
	cin>>s1>>s2;
	//cin>>s1>>s2;
	for(int i = s1.size() - 1,j = 0;i>=0;i--,j++) {
		a[j] = s1[i] - '0';
	}
	for(int i = s2.size() - 1,j = 0;i>=0;i--,j++) {
		b[j] = s2[i] - '0';
	}
	plus_num(a,b,ans);
	int tmp = maxn+1;
	for(int i = tmp;i>0 && ans[tmp] == 0;i--) {
		tmp--;
	}
	for(int i = tmp;i>=0;i--) {
		cout << ans[i];
	}
	
	return 0;
}
