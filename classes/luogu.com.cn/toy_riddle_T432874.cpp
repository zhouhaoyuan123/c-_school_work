#include <iostream>
#include <string>
using namespace std;
string toy[100005];
bool direction[100005];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 0,j = 0;i < n;i++,j = (j - 1 + n) % n) {
		cin>>direction[j]>>toy[j];
	}
	int curr = 0;
	while(m--) {
		int dir,jump;
		cin>>dir>>jump;
		if(!dir) {
			dir = -1;
		}
		else {
			dir = 1;
		}
		if(!direction[curr]) {
			dir = -dir;
		}
		curr = (curr + (dir*jump) + n) % n;
		//cout << toy[curr]<<" ";
	}
//	cout << endl;
	cout << toy[curr];
	return 0;	
}

