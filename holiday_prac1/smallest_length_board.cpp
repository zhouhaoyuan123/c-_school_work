#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int m,s,c;
	cin>>m>>s>>c;
	int occupied[s+1],gap[s + 1],mins = s+50,maxe = 0;
	memset(occupied,0,sizeof(occupied));	
	for(int i = 0;i<c;i++) {
		int t;
		cin>>t;
		occupied[t]++;
		mins = min(mins,t);
		maxe = max(maxe,t);
	}
	int ans = maxe - mins + 1;
	int index = 0,buf = 0;
	for(int i = mins;i<=maxe;i++) {
		if(occupied[i] == 0) {
			buf ++;
		}
		else {
			if(buf != 0) {
				gap[index ++] = buf;
				buf = 0;
			}
		}
	}
	sort(gap,gap + index,greater<int>());
	for(int i = 0;i<min(m - 1,index);i++) {
		ans -= gap[i];
	}
	cout << ans;
	return 0;
}
