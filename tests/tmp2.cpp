#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T --) {
		string num;
		cin>>num;
		int pos = num.find(".");
		if(pos == string::npos) {
			while(num.size() > 1 && num[0] == '0') {
				num.replace(0,1,"");
			}
			if(num.size() > 1) {
				string tmp = num.substr(1);
				while(tmp.size() > 0 && tmp[tmp.size() - 1] == '0') {
					tmp.replace(tmp.size() - 1,1,"");
				}
				if(tmp.size() > 0)
					cout << num[0] << "." << tmp << "E" << num.size() - 1 << endl;
				else 
					cout << num[0] << "E" << num.size() - 1 << endl;
			}
			else {
				cout << num[0] << endl;
			}
		}
		else {
			string tmp = num.substr(0,pos);
			while(tmp.size() > 1 && tmp[0] == '0') {
				tmp.replace(0,1,"");
			}
			if(tmp.size() == 0) 
			{tmp = "0";num.insert(0,"0");}
			string tmp2 = num.substr(1);
			tmp2.replace(tmp2.find("."),1,"");
			while(tmp2.size() > 0 && tmp2[tmp2.size() - 1] == '0') {
				tmp2.replace(tmp2.size() - 1,1,"");
			}
			
		}
	}
	return 0;
}
