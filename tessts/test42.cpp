#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
//	freopen("zip.in","r",stdin);
//	freopen("zip.out","w",stdout);
	int n;
	vector<string> letter;
	string s;
	while(cin>>s) {
		letter.push_back(s);
	}
	n = letter.size();
	cout << letter.size() << " ";
	int zon = 0;int buf = 0;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(letter[i][j] == zon + '0') {
				buf++;
			}
			else {
				cout << "| "<<zon << " | ";
				cout << buf << " ";
				buf = 1;
				zon = !zon;
			}
		}
	}
	return 0;
}
