#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int x,y;
	cin>>x>>y;
	int tmp = 0;
	for(int i = 1;i<=6;i++) {
		for(int j = 1;j<=6;j++) {
			if(i + j >= x || abs(i - j) >= y) {
				tmp ++;
			}
		}
	}
	cout << setprecision(10) << 1.0L * tmp / (1.0L * 6 * 6) << endl;
}
