#include <iostream>
#include <string>
using namespace std;
struct student {
	string name;
	int avg;
	int score;
	char moniter;
	char west;
	int essays;
}people[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>people[i].name>>people[i].avg>>people[i].score>>people[i].moniter>>people[i].west>>people[i].essays;
	}
	long long ans = 0,maxn = 0;
	int index = 0;
	for(int i = 1;i<=n;i++) {
		int tmp = 0;
		if(people[i].avg > 80 && people[i].essays >= 1) {
			tmp += 8000;
		}
		if(people[i].avg > 85 && people[i].score > 80) {
			tmp += 4000;
		}
		if(people[i].avg > 90) {
			tmp += 2000;
		}
		if(people[i].avg > 85 && people[i].west == 'Y') {
			tmp += 1000;
		}
		if(people[i].score > 80 && people[i].moniter == 'Y') {
			tmp += 850;
		}
		ans += tmp;
		if(tmp > maxn) {
			maxn = tmp;
			index = i;
		}
	}
	cout << people[index].name;
	cout << endl << maxn << endl << ans << endl;
	return 0;
}
