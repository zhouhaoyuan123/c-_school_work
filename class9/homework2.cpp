#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	cout << s[0];
	return 0;
}