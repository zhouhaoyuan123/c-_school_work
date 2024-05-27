#include <iostream>
#include <cstring>
using namespace std;
int next_num[1000005];

int main() {
	int q;
	cin>>q;
	//int cur = 0;
	memset(next_num,-1,sizeof(next_num));
	while(q--){
		int op;
		cin>>op;
		if(op == 1) {
			int x,y;
			cin>>x>>y;
			//cache[y] = cur;
			//table[cur] = y;
			next_num[y] = next_num[x];
			next_num[x] = y;
		}
		else if(op == 2) {
			int x;
			cin>>x;
			if(next_num[x] == -1) {
				cout << 0<<endl;
			}
			else {
				cout << next_num[x]<<endl;
			}
		}
		else {
			int x;
			cin>>x;
			next_num[x] = next_num[next_num[x]];
		}
	}
	return 0;
}
