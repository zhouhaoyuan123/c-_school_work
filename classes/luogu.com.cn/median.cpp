#include <iostream>
#include <queue>
using namespace std;
long long num[100005];

int main() {
	int n;
	cin>>n;
	priority_queue<long long,vector<long long>,less<long long> > small;
	priority_queue<long long,vector<long long>,greater<long long> > big;
	for(int i = 0;i<n;i++) {
		long long tmp;
		cin>>tmp;
		num[i+1] = tmp;
	}
	//long long cnt = 0;
	//long long cur = 0;
	for(int i = 1;i<=n;i+=2) {
		if(i == 1) {
			cout << num[i]<<endl;
			big.push(num[i]);
		}
		else {
			big.push(num[i - 1]);
			big.push(num[i]);
			//调整队列
			if(small.size() > 0 && big.size() > 0 && small.top() > big.top()) {
				big.push(small.top());
				small.pop();
			}
			while(!big.empty() && small.size() + 1 < big.size()) {
				small.push(big.top());
				big.pop();
			}
			cout << big.top()<<endl;
			//cur = big.top();
			//big.pop();
		}
	}
	return 0;
}
