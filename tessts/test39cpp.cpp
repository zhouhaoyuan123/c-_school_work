#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
//	freopen("ratio.in","r",stdin);
//	freopen("ratio.out","w",stdout);
	int a,b,l;
	cin>>a>>b>>l;
	a /= __gcd(a,b);
	b /= __gcd(a,b);//a上b下
	if(l >= a && l >= b) {
		cout << a << " " << b;
	}
	else {
		while(!(l >= a && l >= b)) {
			if(a % 2) {
				a ++;
			}
			if(b % 2) {
				b--;
			}
			a /= __gcd(a,b);
			b /= __gcd(a,b);//a上b下
		}
	}
	cout << a << " " << b;
	return 0;
}
