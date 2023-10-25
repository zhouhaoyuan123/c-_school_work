#include <iostream>
using namespace std;
string s1,s2;
int a[101],b[101],c[101];

void strtoint(string src,int des[]) {
	for(int i = 0;i<src.size();i++) {
		des[src.size() - i] = src[i] - '0';
	}
}

int main() {
	cin>>s1>>s2;
	strtoint(s1,a);
	strtoint(s2,b);
	int la = s1.size();
	int lb = s2.size();
	int lc = max(la,lb);
	for(int i = 1;i<=lc;i++) {
		c[i]=a[i] + b[i] + c[i];
		c[i+1]=c[i]/10;
		c[i] %= 10;
	}
	while(c[lc] == 0 && lc > 1) lc--;
	
	for(int i = lc;i>=1;i--) {
		cout << c[i];
	}
	return 0;
}
