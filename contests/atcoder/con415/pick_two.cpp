#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	int lastnum = 0;
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '#') {
			if(lastnum) {
				cout << i + 1 << "\n";
				lastnum = 0;
			}
			else {
				cout << i + 1 << ",";
				lastnum = i + 1;
			}
		}
	}
	cout << endl;
	return 0;
}
