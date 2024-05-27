#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 6050;//max len;
/*times_num_simple XXXXXX * X 
  move_left XX -> XX0
  times_num XXX * XXX */
int a[maxn + 5],b[maxn+5],ans[maxn+5],ans2[maxn+5];
int times_num_simple(int a[],int lena,int b,int ans[]) {
	//memset(ans,0,sizeof(ans));
	for(int i = 0;i<lena;i++) {
		ans[i] += a[i] * b;
		if(ans[i] > 9) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}
	int tmp = lena;
	if(ans[lena] > 0) {
		tmp++;
	}
	return tmp;
}
void move_left(int a[],int lena,int len_move) {
	for(int i = lena - 1;i>=0;i--) {
		a[i + len_move] = a[i];
	}
	for(int i = len_move - 1;i>=0;i--) {
		a[i] = 0;
	}
}
void plus_num(int a[],int b[]) {
	for(int i = 0;i<maxn;i++) {
		a[i] += b[i];
		if(a[i] > 9) {
			a[i+1] ++;
			a[i] -= 10;
		}
	}	
}
void times_num(int a[],int lena,int b[],int lenb,int ans[],int maxlen) {
	for(int i = 0;i<lenb;i++) {
		int tmp[maxn];
		memset(tmp,0,sizeof(tmp));
		times_num_simple(a,lena,b[i],tmp);
		move_left(tmp,maxlen - lenb - 1,i);
		plus_num(ans,tmp);
	}
}
int main() {
	int s;
	cin>>s;
	ans[0] = 1;
	for(int i = 1;i<=s;i++) {
		int tmp[maxn];
		memset(tmp,0,sizeof(tmp));
		times_num_simple(ans,maxn,i,tmp);
		for(int i = 0;i<maxn;i++) {
			ans[i] = tmp[i];
		}
		plus_num(ans2,ans);
	}
	int tmp = maxn+1;
	for(int i = maxn+1;i>0 && ans2[i] == 0 ; i--) {
		tmp--;
	}
	for(int i = tmp;i>=0;i--) {
		cout << ans2[i];
	}
	return 0;
}
