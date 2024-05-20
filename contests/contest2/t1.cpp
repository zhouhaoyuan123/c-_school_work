#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	int N,T,x;
	cin>>N>>T>>x;
	double tmpx = x;
	double ans = 0;
	for(int i = 0;i<N - 1;i++) {
		ans += tmpx;
		//cout << tmpx << " ";
		if(tmpx >= T) {
			tmpx = x;
		}
		else {
			tmpx *= 1.1;
		}
	}
	cout << fixed << setprecision(2)<<ans;
	return 0;
}
