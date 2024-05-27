#include <iostream>
#include <cstring>
using namespace std;
int n;
int dir[5005];
int index_num = 1,sum = 0;
int cnt = 0;
int tmp[5005];
bool judge(int k) {
	memset(tmp,0,sizeof(tmp));
	for(int i = 1;i<=n;i++) {
		tmp[i] = dir[i];
	}
	int cur = 0;
	cnt = 0;
	for(int i = 1;i<=n;i++) {
		cur ^= tmp[i];
		if(!cur) {
			if(i + k - 1 > n) {
				return false;
			}
			cnt++;
			if(cnt >= sum) {
				return false;
			}
			tmp[i] ^= 1;
			tmp[i + k] ^= 1;
			cur ^= 1;
		}
	}
	return true;
}

int main() {
	cin>>n;
	bool last = 0;
	for(int i = 1;i<=n;i++) {
		char op;
		cin>>op;
		if(op == 'B') {
			dir[i] = 0;
			sum++;
		}
		else {
			dir[i] = 1;
		}
		dir[i] ^= last;
		if(op == 'B' ) {
			last = 0;
		}
		else {
			last = 1;
		}
	}
	for(int i = 2;i<=n;i++) {
		if(judge(i)) {
			index_num = i;
			sum = cnt;
		}
	}
	cout << index_num << " "<<sum;
	return 0;
}
