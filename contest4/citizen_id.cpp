#include <iostream>
#include <string>
using namespace std;

int main() {
	string id;
	cin>>id;
	cout << id.substr(6,4)<<" ";
	if(id[6+4] == '0'){
		cout << id[6+4+1]<<" ";
	}
	else {
		cout << id.substr(6+4,2)<<" ";
	}
	if(id[6+4+2] == '0'){
		cout << id[6+4+2+1]<<" ";
	}
	else {
		cout << id.substr(6+4+2,2)<<" ";
	}
	return 0;
}
