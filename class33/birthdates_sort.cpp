#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct date {
	string name;
	int y,m,d;
	int id;
};
bool cmp(date x,date z) {
	if(x.y == z.y) {
		if(x.m == z.m) {
			if(x.d == z.d) {
				return x.id > z.id;
			}
			return x.d < z.d;
		}
		return x.m < z.m;
	}
	return x.y < z.y;
}

int main() {
	int n;
	cin>>n;
	date birth[n];
	for(int i = 0;i<n;i++) {
		cin>>birth[i].name>>birth[i].y >> birth[i].m>>birth[i].d;
		birth[i].id = i+1;
	}
	sort(birth,birth + n,cmp);
	for(int i = 0;i<n;i++) {
		cout << birth[i].name<<endl;
	}
	return 0;
}
