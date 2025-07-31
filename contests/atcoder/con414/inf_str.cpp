#include <iostream>
#include <string>
using namespace std;

int main() {
	string s,interval = "";
	long long num;
	cin>>s>>num;
	for(int i = 0;i<s.size() - 1;i++) {
		interval += s;
		s.insert(0,1,s[s.size() - 1]);
		s.replace(s.size() - 1,1,"");
	}
	cout << interval << " " << interval[num % interval.size()] << endl;
	return 0;
}
