#include <iostream>
#include <algorithm>
using namespace std;
struct timeline {
	int l;
	int r;
};
bool cmp(timeline x,timeline y) {
	return x.l < y.l;
}

int main() {
	int n;
	cin>>n;
	timeline num[n];
	for(int i = 0;i<n;i++) {
		cin>>num[i].l>>num[i].r;
	}
	sort(num,num+n,cmp);
	int maxactive = 0,maxidle = 0; 
	int i = 0;
	bool flag = 1;int buf = num[0].r - num[0].l,buf2 = -1;
	for(int j = 1;j<n;j++) {
		if(num[j].l >= num[i].l && num[j].r <= num[i].r) {
			continue;
		}
		if((num[j].l - 1 == num[i].r) || (num[j].l <= num[i].r && num[j].r > num[i].r)) {
			flag = 1;
			buf += num[j].r - num[i].r;
			//cout << buf<<"!"<<endl;
		}
		else if(flag) {
			flag = 0;
			if(buf > maxactive) {
				maxactive = buf;
			}
			//cout << buf<<endl;
			buf = num[j].r - num[j].l;
			//cout << buf<<" ";
		}
		else {
			if(buf > maxactive) {
				maxactive = buf;
			}
			//cout << buf<<endl;
			buf = num[j].r - num[j].l;
		}
		if(!flag) {
			//cout << "here"<<" "<<j<<" " << i << endl;
			buf2 = num[j].l - num[i].r;
			if(maxidle < buf2) {
				maxidle = buf2;
			}
		}
		i = j;
	}
	if(buf > maxactive) {
		maxactive = buf;
	}
	cout << maxactive << " "<<maxidle;
	return 0;
}
