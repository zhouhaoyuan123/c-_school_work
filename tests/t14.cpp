//apt like manager by Aaron(zhouhaoyuan2012@foxmail.com)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int main(int argc , char * argv[]) {
	if(argc == 1) {
		cout << "This is the backend program , for more details please visit the respository . " << endl;
	}
	else if (argc == 2 || argc == 3) {
		bool silent = false;
		if(argc == 3) {
			if(strcmp(argv[2],"-s") == 0) {
				silent = true;
			}
		}
		if(freopen(argv[1],"r",stdin) == NULL) {
			if(!silent) cout << "Error : File not found ! " << endl;
			return -1;
		}
		//pre operation
		int n;
		cin>>n;
		if(n < 0) return -3;
		//requirements
		int i = 1;
		while(n --) {
			string cmd;
			getline(cin,cmd);
			int status = system(cmd.c_str());
			if(status != 0) {
				if(!silent) cout << "Error : Requirements not statisfied : " << cmd << " id : " << i << endl;
				return -1;
			}
			i++;
		}
		i = 0;
		//-------------------
		//ops;
		cin>>n;
		if(n < 0) return -3;
		while(n --) {
			string cmd;
			getline(cin,cmd);
			int status = system(cmd.c_str());
			if(status != 0) {
				if(!silent) cout << "Warn : Task exited abnormally : " << cmd << " id : " << i << endl;
			}
			i++;
		}
		i = 0;
		//-------------------
		//triggers
		cin>>n;
		if(n < 0) return -3;
		while(n --) {
			string cmd;
			getline(cin,cmd);
			int status = system(cmd.c_str());
			if(status != 0) {
				if(!silent) cout << "Warn : Trigger exited abnormally : " << cmd << " id : " << i << endl;
			}
			i++;
		}
	}
	else {
		cout << "Invalid arguments ! " << endl;
		return -2;
	}
	return 0;
}
