/*
  ID: liu_min1
  PROG: friday
  LANG: C++                 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int months[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans[10];

int main() {
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int n;
	cin>>n;
	int current = -1;
	for(int i = 1900;i<=1900 + n - 1;i++) {
		bool isLeap = ( (i % 100 == 0 && i % 400 == 0) || (i % 100 != 0 && i % 4 == 0) );
		for(int j = 1;j<=12;j++) {
			if(j == 2 && isLeap) {
				months[2] = 29;
			}
			else {
				months[2] = 28;
			}
			//cout << "here2"<<endl;
			for(int k = 1;k<=months[j];k++) {
				current = (current + 1) % 7;
				if(k == 13) {
					ans[current] ++;
				}
			}
		}
		//cout << "here"<<endl;
	}
	cout << ans[5] <<" "<<ans[6]<<" "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<endl;
	return 0;
}
