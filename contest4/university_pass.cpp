#include <iostream>
using namespace std;

int main() {
	int a,b,c,d,e,f,limit;
	cin>>a>>b>>c>>d>>e>>f>>limit;
	int cnt = a+b+c+d+e+f;
	if(cnt >= limit) {
		cout << "Congratulate!";
	}
	else {
		cout << "Sorry";
	}
	return 0;
}
