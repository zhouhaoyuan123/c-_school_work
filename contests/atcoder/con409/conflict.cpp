#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	for(int i = 0;i<a.size();i++) {
		if(a[i] == 'o' && b[i] == 'o') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
