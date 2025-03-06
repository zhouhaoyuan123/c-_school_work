#include <iostream>
#include <algorithm>
using namespace std;
int e[15];
struct person {
	int num,id;
}num[20005];
bool cmp(person x,person y) {
	if(x.num != y.num) {
		return x.num > y.num;
	}
	return x.id < y.id;
}

int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=10;i++) {
		cin>>e[i];
	}
	for(int i = 1;i<=n;i++) {
		cin>>num[i].num;
		num[i].id = i;
	}
	sort(num+1,num+1+n,cmp);
	for(int i = 1;i<=n;i++) {
		num[i].num += e[(i - 1) % 10 + 1];
		//cout << num[i].num << " ";
	}
	//cout << endl;
	sort(num + 1,num + 1 + n,cmp);
	for(int i = 1;i<=k;i++) {
		cout << num[i].id << " ";
	}
	cout << endl;
	return 0;
}
