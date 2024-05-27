#include <iostream>
#include <algorithm>
using namespace std;
struct student {
	int id;
	int all;
	int cn;
}stu[305];
bool cmp(student x,student y) {
	if(x.all == y.all) {
		if(x.cn == y.cn) {
			return x.id < y.id;
		}
		return x.cn > y.cn;
	}
	return x.all > y.all;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		stu[i].id = i;
		stu[i].cn = t1;
		stu[i].all = t1+t2+t3;
	}
	sort(stu+1,stu+1+n,cmp);
	for(int i = 1;i<=min(n,5);i++) {
		cout << stu[i].id <<" "<<stu[i].all<<endl;
	}
	return 0;
}
