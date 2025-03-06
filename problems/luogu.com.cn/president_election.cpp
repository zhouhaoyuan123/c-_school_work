#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct president {
	int id;
	string num;
}people[25];
bool cmp (president x,president y) {
	if(x.num == y.num) {
		return x.id < y.id;
	}
	if(x.num.size() == y.num.size())
		return x.num > y.num;
	return x.num.size() > y.num.size();
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>people[i].num;
		people[i].id = i;
	}
	sort(people + 1,people + 1 + n,cmp);
	cout << people[1].id << endl << people[1].num << endl;
	return 0;
}
