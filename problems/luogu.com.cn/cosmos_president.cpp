#include <iostream>
#include <algorithm>
using namespace std;
struct person {
	int id;
	string votes;
};
person people[25];
bool cmp (person x,person y) {
	if(x.votes.size() == y.votes.size())
		return x.votes > y.votes;
	return x.votes.size() > y.votes.size();
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>people[i].votes;
		people[i].id = i;
	}
	sort(people + 1,people + 1 + n,cmp);
	cout << people[1].id << endl << people[1].votes;
	return 0;
}
