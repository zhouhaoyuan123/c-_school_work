#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int maxn = 505;//max len;
/*times_num_simple XXXXXX * X 
  move_left XX -> XX0
  times_num XXX * XXX */
int a[maxn + 5],b[maxn+5],ans[maxn+5],ans3[maxn+5];
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
		if(i + len_move > maxn)  {
			continue;
		}
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
		move_left(tmp,maxlen,i);
		plus_num(ans,tmp);
	}
}
void minus_num(int a[],int b[]) {
	for(int i = 0;i<maxn;i++) {
		a[i] -= b[i];
		if(a[i] < 0) {
			a[i + 1] --;
			a[i] += 10;
		}
	}
}

int main() {
	int p;
	cin>>p;
	cout << floor(1.0 * p * log10(2)) + 1<<endl;
	int tmp = 0;
	a[0] = 2;
	ans3[0] = 1;
	for(;p!=1;) {
		int ans2[maxn+5];
		memset(ans2,0,sizeof(ans2));
		if(p % 2 == 0) {
			times_num(a,maxn,a,maxn,ans2,maxn);
			memset(a,0,sizeof(ans));
			plus_num(a,ans2);
			p /= 2;
		}
		else {
			times_num(ans3,maxn,a,maxn,ans2,maxn);
			memset(ans3,0,sizeof(ans));
			plus_num(ans3,ans2);
			p--;
		}
	}
	int ans4[maxn+5];
	memset(ans4,0,sizeof(ans4));
	times_num(a,maxn,ans3,maxn,ans4,maxn);
	memset(ans,0,sizeof(ans));
	ans[0] = 1;
	minus_num(ans4,ans);
	tmp = 0;
	for(int i = 500 - 1;i>=0;i--) {
		cout << ans4[i];
		tmp++;
		if(tmp % 50 == 0) {
			cout << endl;
		}
	}
	return 0;
}
