#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 6050;//max len;
/*times_num_simple XXXXXX * X 
 move_left XX -> XX0
 times_num XXX * XXX */
int a[maxn + 5],b[maxn+5],ans[maxn+5];
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
	string s1,s2;
	cin>>s1>>s2;
	for(int i = s1.size() - 1,j = 0;i>=0;i--,j++) {
		a[j] = s1[i] - '0';
	}
	for(int i = s2.size() - 1,j = 0;i>=0;i--,j++) {
		b[j] = s2[i] - '0';
	}
	times_num(a,2005,b,2005,ans,maxn);
	int tmp = maxn+1;
	for(int i = maxn+1;i>0 && ans[i] == 0 ; i--) {
		tmp--;
	}
	for(int i = tmp;i>=0;i--) {
		cout << ans[i];
	}
	return 0;
}
