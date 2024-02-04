#include <iostream>
using namespace std;
int matches[10] = {6,2,5,5,4,5,6,3,7,6};
int a[3];
int get_num(int n) {
	int ans = 0;
	if(n == 0) {
		return matches[0];
	}
	while(n>0) {
		ans += matches[n % 10];
		n/=10;
	}
	return ans;
}
int cnt = 0;

void dfs(int n,int step,int buf) {
	if(n < 2) {
		return;
	}
	if(step == 2) {
		a[2] = a[0] + a[1];
		if(n == get_num(a[2])) {
			//cout << a[0]<<"+"<<a[1]<<"="<<a[2]<<endl;
			cnt++;
		}	
		a[2] = 0;
		return;
	}
	for(int i = 0;i<=9;i++) {
		if(n - matches[i] >= 2) {
			if(buf * 10 + i == 0 && buf == 0) {
				a[step] = 0;
				dfs(n - matches[0],step + 1,0);
			}
			else {
				dfs(n - matches[i],step,buf * 10 + i);
				a[step] = buf * 10 + i;
				dfs(n - matches[i],step+1,0);
				a[step] = 0;
			}	
		}
	}
}

int main() {
	int n;
	cin>>n;
	dfs(n - 4,0,0);
	cout << cnt;
	return 0;
}
