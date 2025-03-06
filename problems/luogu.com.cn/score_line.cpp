#include <iostream>
#include <algorithm>
using namespace std;
struct person {
	int id,score;
}scores[5005];
bool cmp(person x,person y) {
	if(x.score == y.score) {
		return x.id < y.id;
	}
	return x.score > y.score;
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>scores[i].id >> scores[i].score;
	}
	sort(scores + 1,scores + 1 + n,cmp);
	int k = m * 1.5;
	int limit = scores[min(n,k)].score;
	int cnt = 1;
	int ans = 1;
	while(ans <= n) {
		if(scores[ans].score >= limit) {
			cnt ++;
		}
		else {
			break;
		}
		ans ++;
	}
	cout << limit << " " << ans - 1 << endl;
	for(int i = 1;i<=ans - 1;i++) {
		cout << scores[i].id << " " << scores[i].score << endl;
	}
	return 0;
}

