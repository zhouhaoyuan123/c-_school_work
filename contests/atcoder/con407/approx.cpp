#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	double tmp = 1.0  * a / b;
	if(ceil(tmp) - tmp <= tmp - floor(tmp)) {
		cout << ceil(tmp) << endl;
	}
	else {
		cout << floor(tmp) << endl;
	}
	return 0;
}
