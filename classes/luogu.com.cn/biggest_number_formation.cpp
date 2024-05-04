#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string num[25];
bool cmp(string x,string y) {
	string x1 = x + y;
	string x2 = y + x;
	return x1 > x2;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+n,cmp);
	for(int i = 1;i<=n;i++) {
		cout << num[i];
	}
	return 0;
}
