#include <iostream>
using namespace std;
int left_num[30],right_num[30];

void dfs(int cur) {
	if(cur == -1){
		return;
	}
	cout << char(cur + 'a');
	dfs(left_num[cur]);
	dfs(right_num[cur]);
}
int main() {
	int n;
	cin>>n;
	char begin_letter;
	for(int i = 0;i<n;i++) {
		char op;
		cin>>op;
		if(i == 0) {
			begin_letter = op;
		}
		char tmp,tmp2;
		cin>>tmp>>tmp2;
		if(tmp != '*') {
			left_num[int(op - 'a')] = int(tmp - 'a');
		}
		else {
			left_num[int(op - 'a')] = -1;
		}
		if(tmp2 != '*') {
			right_num[int(op - 'a')] = int(tmp2 - 'a');
		}
		else {
			right_num[int(op - 'a')] = -1;
		}
	}
	dfs(begin_letter - 'a');
	return 0;
}
