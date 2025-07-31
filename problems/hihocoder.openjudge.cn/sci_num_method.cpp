#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T --) {
		string num;
		cin>>num;
		if(num.find(".") == string::npos) {
			num += ".";
		}
		string ans1 = "0.";
		int ans2 = 0;
		string part1 = num.substr(0,num.find(".") + 1);
		string part2 = num.substr(num.find("."));
		while(part1.size() && part1.front() == '0') {
			part1.replace(0,1,"");
		}
		while(part2.size() && part2.back() == '0') {
			part2.replace(part2.size() - 1,1,"");
		}
		part1.replace(part1.size() - 1,1,"");
		part2.replace(0,1,"");
		if(part1.size() > 0) {
			ans1 = part1[0];
			ans1 += "."+part1.substr(1)+part2;
			ans2 = part1.size() - 1;
		}
		else {
			for(int i = 0;i<part2.size();i++) {
				if(part2[i] > '0') {
					ans1 = part2[i];
					ans1 += "." + part2.substr(i + 1);
					ans2 = -i - 1;
					break;
				}
			}
		}
		if(ans1.find(".") != string::npos) {
			while(ans1.size() > 0 && ans1.back() == '0') {
				ans1.replace(ans1.size() - 1,1,"");
			}
			if(ans1.back() == '.') {
				ans1.replace(ans1.size() - 1,1,"");
			}
		}
		if(ans2 == 0) {
			cout << ans1 << endl;
		}
		else {
			cout << ans1 << "E" << ans2 << endl;
		}
	}
	return 0;
}
