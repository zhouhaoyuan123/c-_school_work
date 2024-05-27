#include <iostream>
#include <algorithm>
using namespace std;
int num[500005];
struct number {
	int num;
	int id;
};
bool cmp(number x,number y) {
	if(x.num == y.num) {
		return x.id < y.id;
	}
	return x.num < y.num;
}
number digit1[500005],digit2[500005],digit3[500005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		digit1[i].num = num[i] % 10;
		digit1[i].id = i;
		digit2[i].num = num[i] /10 % 10;
		digit2[i].id = i;
		digit3[i].num = num[i] /100 % 10;
		digit3[i].id = i;
	}
	sort(digit1+1,digit1+1+n,cmp);
	sort(digit2+1,digit2+1+n,cmp);
	sort(digit3+1,digit3+1+n,cmp);
	for(int i = 1;i<=n;i++) {
		//cout << digit1[i].num <<" | ";
		cout << num[digit1[i].id]<<" ";
	}
	cout << endl;
	for(int i = 1;i<=n;i++) {
		cout << num[digit2[i].id]<<" ";
	}
	cout << endl;
	for(int i = 1;i<=n;i++) {
		cout << num[digit3[i].id]<<" ";
	}
	cout << endl;
	return 0;
}
