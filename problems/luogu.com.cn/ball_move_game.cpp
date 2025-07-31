#include <iostream>
using namespace std;
int num[200005];
int dict[200005];

int main() {
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++) {
		num[i] = i;
		dict[i] = i;
	}
	while(q --) {
		int op;
		cin>>op;
		if(dict[op] == n && n > 1) {
			swap(num[dict[op]],num[dict[op] - 1]);
			dict[op] = n - 1,dict[num[n]] = n;
		}
		else if(n > 1) {
			swap(num[dict[op]],num[dict[op] + 1]);
			dict[num[dict[op]]] --;
			dict[op] ++;
		}
	}
	for(int i = 1;i<=n;i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	return 0;
}
