#include <iostream>
using namespace std;
int timeline[1000005];

int main() {
	int n;
	cin>>n;
	int maxr = 0,minl = 1e6 + 5;
	for(int i = 0;i<n;i++) {
		int l,r;
		cin>>l >> r; 
		timeline[l] += 1;
		timeline[r] -= 1;
		if(maxr < r) {
			maxr = r;
		}
		if(minl > l) {
			minl = l;
		}
	}
	int maxactive = 0,maxidle = 0; 
	bool flag = 0;int buf = 0,buf2 = -1,cnt = 0;
	for(int i = minl;i<=maxr;i++) {
		if(cnt + timeline[i] > 0 && !flag) {
			cnt+=timeline[i];
			//cout<< i << " "<<cnt<<" "<<buf <<endl;
			flag = true;
			if(maxidle < buf2 + 1) {
				maxidle = buf2 + 1;
			}
			buf2 = 0;
		}
		else if(cnt + timeline[i] <= 0 && flag) {
			cnt = 0;
			//cout<< i << " "<<cnt<<" "<<buf <<endl;
			flag = false;
			if(maxactive < buf + 1) {
				maxactive = buf + 1;
			}
			//cout << buf<<endl;
			buf = 0;
		}
		else if(flag){
			cnt += timeline[i];
			buf ++;
		}
		else {
			buf2 ++;
		}
	}
	cout << maxactive << " "<<maxidle;
	return 0;
}
