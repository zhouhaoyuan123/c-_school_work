/*
  ID: liu_min1
  PROG: gift1
  LANG: C++                 
 */
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

string names[15];
map<string,int> money;

int main() {
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int NP;
	cin>>NP;
	for(int i = 0;i<NP;i++)  {
		cin>>names[i];
	}
	for(int i = 0;i<NP;i++) {
		string name;
		cin>>name;
		int average = 0;
		int giveout,num;
		cin>>giveout>>num;
		if(num != 0) {
			average = giveout / num;
			money[name]+=giveout % num;
			money[name] -= giveout;
		}
		for(int i = 0;i<num;i++) {
			string s;
			cin>>s;
			money[s] += average;
		} 
	}
	for(int i = 0;i<NP;i++) {
		cout << names[i] <<" "<<money[names[i]]<<endl;
	}
	return 0;
}
