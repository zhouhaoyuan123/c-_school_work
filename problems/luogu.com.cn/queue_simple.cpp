#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin>>n;
	queue<int> q;
	while(n --) {
		int op;
		cin>>op;
		if(op == 1) {
			int x;
			cin>>x;
			q.push(x);
		}
		else if(op == 2) {
			if(q.size() == 0) {
				cout << "ERR_CANNOT_POP"<<endl;
				continue;
			}
			q.pop();
		}
		else if(op == 3) {
			if(q.size() == 0) {
				cout << "ERR_CANNOT_QUERY"<<endl;
				continue;
			}
			cout << q.front()<<endl;
		}
		else {
			cout << q.size()<<endl;
		}
	}
	return 0;
}
