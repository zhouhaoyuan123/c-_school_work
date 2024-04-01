#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
struct person {
	int id;
	long long time_num;
	int index;
}people[300005];
vector <int> nation(300005,0);
int ans[100005];

int main() {
	int n;
	cin>>n;
	int cnt = 0;
	for(int i = 0;i<n;i++) {
		int t,k;
		cin>>t>>k;
		for(int j = 0;j<k;j++) {
			int tmp;
			cin>>tmp;
			people[cnt++].time_num = t;
			people[cnt - 1].id = tmp;
			people[cnt - 1].index = cnt - 1;
		}
	}
	queue<person> q;
	set<int> st;
	q.push(people[0]);
	int cur = 0;
	nation[people[0].id] ++;
	st.insert(people[0].id);
	for(int i = 0;i<=cnt;i++) {
		if(people[cur].time_num != people[i].time_num) {
			cout << st.size()<<endl;
			cur = i;
		}
		if(people[i].time_num - q.front().time_num < 86400) {
			q.push(people[i]);
			nation[people[i].id] ++;
			st.insert(people[i].id);	
		}
		else {
			//cout << st.size() <<endl;
			while(!q.empty() && people[i].time_num - q.front().time_num >= 86400) {
				nation[q.front().id] --;
				if(nation[q.front().id] <= 0) {
					st.erase(q.front().id);
				}
				q.pop();
			} 
			if(q.empty()) {
				//cur = i;
				q.push(people[i]);
				nation[q.front().id] ++;
				st.insert(people[i].id);
				continue;
			}
			//cur = q.front().index;
			i--;
		}
	}
	return 0;
}
