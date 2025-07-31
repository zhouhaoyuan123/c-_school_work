#include <iostream>
using namespace std;
int mem[105];
int index = 0;
bool alloc(int n,int cnt) {
	int tmp = 0;
	int ans = -1;
	for(int i = 1;i<=n;i++) {
		if(mem[i] == 0 && mem[i - 1] == 0) {
			tmp ++;
		}
		else if(mem[i] == 0) {
			tmp = 1;
		}
		else {
			tmp = 0;
		}
		if(tmp >= cnt) {
			ans = i - cnt + 1;
			break;
		}
	}
	if(ans == -1) return 1;
	++index;
	for(int i = ans;i<=ans + cnt - 1;i++) {
		mem[i] = index;
	}
	return 0;
}
bool erase(int n,int x) {
	bool flag = 1;
	for(int i = 1;i<=n;i++) {
		if(mem[i] == x) {
			flag = 0;
			mem[i] = 0;
		}
	}
	return flag;
}
void defragment(int n) {
	int j = 1;
	for(int i = 1;i<=n;i++) {
		if(mem[i]) {
			mem[j ++] = mem[i];
		}
	}
	for(;j<=n;j++) {
		mem[j] = 0;
	}
}

int main() {
	int t,m;
	cin>>t>>m;
	while(t --) {
		string op;
		cin>>op;
		if(op == "alloc") {
			int x;
			cin>>x;
			bool flag = alloc(m,x);
			if(flag) {
				cout << "NULL" << "\n";
			}
			else {
				cout << index << "\n";
			}
		}
		else if(op == "erase") {
			int x;
			cin>>x;
			bool flag = erase(m,x);
			if(flag) {
				cout << "ILLEGAL_ERASE_ARGUMENT" << "\n";
			}
		}
		else {
			defragment(m);
		}
	}
	cout << endl;
	return 0;
}
