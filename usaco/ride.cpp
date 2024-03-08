/*
  ID: liu_min1
  PROG: ride
  LANG: C++                 
 */
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int mod = 47;

int main() {
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string comet,group;
	cin>>comet>>group;
	int ans1 = 1,ans2 = 1;
	for(int i = 0;i<comet.size();i++) {
		if('A' <= comet[i] && comet[i] <= 'Z') {
			ans1 *= (comet[i] - 'A' + 1);
			ans1 %= mod;
		}
	}
	for(int i = 0;i<group.size();i++) {
		if('A' <= group[i] && group[i] <= 'Z') {
			ans2 *= (group[i] - 'A' + 1);
			ans2 %= mod;
		}
	}
	if(ans1 == ans2) {
		cout << "GO"<<endl;
	}
	else {
		cout << "STAY"<<endl;
	}
}
