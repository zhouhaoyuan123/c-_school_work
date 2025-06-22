#include <iostream>
#include <string>
using namespace std;
string server;
int input_op[200005];
int index_s[200005];
bool vis[200005];
string nums[200005];

int main() {
	int n,q;
	cin>>n>>q;
	int i = 1;
	int tmp = 0;
	while(q --) {
		cin>>input_op[i];
		int op = input_op[i];
		if(op == 1) {
			int p;
			cin>>p;
			index_s[i] = p;
		}
		else if(op == 2) {
			int p;cin>>p;
			string s;
			cin>>s;
			index_s[i] = p;
			nums[i] = s;
		}
		else {
			int p;cin>>p;
			index_s[i] = p;
			tmp = i;
		}
		i++;
	}
	int tmp2 = index_s[tmp];
	bool flag = 0;
	for(int j = tmp;j>=1;j--) {
		if(flag) {
			if(input_op[j] == 3) {
				vis[j] = 1;
				flag = 0;
				tmp2 = index_s[j];
			}
			continue;
		}
		if(index_s[j] == tmp2) {
			vis[j] = 1;
			if(input_op[j] == 1) {
				flag = true;
			}
		}
	}
	for(int j = 1;j<=i;j++) {
		if(vis[j]) {
			int op = input_op[j];
			if(op == 2) {
				string s = nums[j];
				server += s;
			}
		}
	}
	cout << server << endl;
	return 0;
}
