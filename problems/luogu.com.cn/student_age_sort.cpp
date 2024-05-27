#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct student {
	int id;
	int year,month,date;
	string name;
}person[105];
bool cmp(student x,student y) {
	if(x.year == y.year) {
		if(x.month == y.month) {
			if(x.date == y.date) {
				return x.id > y.id;
			}
			return x.date < y.date;
		}
		return x.month < y.month;
	}
	return x.year < y.year;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>person[i].name>>person[i].year>>person[i].month>>person[i].date;
		person[i].id = i;
	}
	sort(person+1,person + 1 + n,cmp);
	for(int i = 1;i<=n;i++) {
		cout << person[i].name << endl;
	}
	return 0;
}
