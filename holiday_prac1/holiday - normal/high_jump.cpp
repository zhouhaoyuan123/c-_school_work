#include <iostream>
#include <algorithm>
using namespace std;

struct person {
	int h,s;
}people[100005];
bool cmp(person x,person y) {
	if(x.s == y.s) {
		return x.h < y.h;
	} 
	return x.s > y.s;
}

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>people[i].h>>people[i].s;
	}
	sort(people,people+n,cmp);
	for(int i = 0;i<n;i++) {
		if(i == 0 || !(people[i].h == people[i - 1].h && people[i].s == people[i - 1].s)) {
			cout << people[i].h<<" "<<people[i].s<<endl;
		}
	} 
	return 0;
}
