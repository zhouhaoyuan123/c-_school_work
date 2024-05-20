#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int a,b,c,d;
double calc(double x) {
	return a * x * x * x + b * x * x + c * x+d;
}
double ans[3];
int cnt = 0;

int main() {
	cin>>a>>b>>c>>d;
	//search(false,-100,100);
	for(int i = -100;i<=100;i++) {
//		if(calc(i) == 0) {
//			ans[cnt++] = i;
//			continue;
//		}
		if(cnt < 3 && calc(i) == 0) {
			cout << fixed << setprecision(2)<<1.0 * i<<" ";
			cnt ++;
		}
		if(cnt < 3 && calc(i) * calc(i+1) <0) {
			//cout << j << " "<<i<<endl;
			//cout << endl;
			double l = i,r = i + 1;
			while(r - l >= 0.0001) {
				double mid = l + (r - l) / 2;
				if(calc(l) * calc(mid) <= 0) {
					r = mid;
				}
				else {
					l = mid;
				}
			}
			cout << fixed << setprecision(2)<<l<<" ";
			//cout << "TICK";
			cnt++;
		}
		if(cnt >= 3) {
			break;
		}
	}
	//search(4,6);
	return 0;
}
