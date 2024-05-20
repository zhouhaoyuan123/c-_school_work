#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct seat {
	int id;
	long long num;
	friend bool operator < (seat x,seat y) {
		return x.num < y.num;
	}
}seats[200005];
bool cmp(seat x,seat y) {
	return x.num < y.num;
}
priority_queue <seat> q;

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>seats[i].num;
		seats[i].id = i;
	}
	sort(seats,seats+n,cmp);
	int cnt = 0;
	for(int i = 0;i<2*n;i++) {
		char op;
		cin>>op;
		if(op == '0') {
			q.push(seats[cnt]);
			cout << seats[cnt].id + 1<<" ";
			cnt++;
		}
		else {
			cout << q.top().id + 1<< " ";
			q.pop();
		}
	}
	return 0;
}
