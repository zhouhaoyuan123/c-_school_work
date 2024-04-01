#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 10087;
int a[maxn + 5],b[maxn + 5];
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
	string s1,s2;
	cin>>s1>>s2;
	//cin>>s1>>s2;
	for(int i = s1.size() - 1,j = 0;i>=0;i--,j++) {
		a[j] = s1[i] - '0';
	}
	for(int i = s2.size() - 1,j = 0;i>=0;i--,j++) {
		b[j] = s2[i] - '0';
	}
	if(s1.size() > s2.size() || (s1.size() == s2.size() && s1 >= s2)) {
		minus_num(a,b);
		int tmp = maxn+1;
		for(int i = tmp;i>0 && a[tmp] == 0;i--) {
			tmp--;
		}
		for(int i = tmp;i>=0;i--) {
			cout << a[i];
		}
	}
	else {
		minus_num(b,a);
		int tmp = maxn+1;
		for(int i = tmp;i>0 && b[tmp] == 0;i--) {
			tmp--;
		}
		cout <<"-";
		for(int i = tmp;i>=0;i--) {
			cout << b[i];
		}
	}
	
	return 0;
}
