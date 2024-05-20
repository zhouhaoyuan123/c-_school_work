#include <iostream>
#include <cstring>
using namespace std;

long long bucket[2 * 100000 + 5];
long long limit[2 * 100000 + 5];
int order[2 * 100000 + 5];
char sequence[2 * 100000 + 5];

int main() {
	int n;
	long long m,cnt = 0;
	cin>>n>>m;
	cin>>sequence;
	for(int i = 0;i<n;i++) {
		cin>>bucket[i];
		limit[i] = bucket[i];
		cnt+=bucket[i];
	}
	for(int i = 0;i<n;i++) {
		if(sequence[i] == 'L') {
			order[i] --;
			order[(i - 1 + n) % n] ++;
		}
		else {
			order[i] --;
			order[(i + 1) % n] ++;
		}
	}
	for(int i = 0;i<m;i++) {
		bool flag = false;
		for(int j = 0;j<n;j++) {
			bucket[j] += order[j];
			if(bucket[j] <= 0) {
				flag = true;
			}
			else if(bucket[j] > limit[j]){
				cnt -= (bucket[j] - limit[j]);
				bucket[j] = limit[j];
			}
		}
		if(flag) {
			memset(order,0,sizeof(order));
			for(int i = 0;i<n;i++) {
				if(bucket[i] == 0) {
					continue;
				}
				if(sequence[i] == 'L') {
					order[i] --;
					order[(i - 1 + n) % n] ++;
				}
				else {
					order[i] --;
					order[(i + 1) % n] ++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
