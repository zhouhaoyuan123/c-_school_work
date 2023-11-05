#include<iostream>
#include<cstring>
using namespace std;
string stu[100];
char ganbu[100], west[100];
int fina[100], clas[100], article[100], money[100], maxx = 0, total = 0, i, n, k;

int main() {
//	freopen("money.in", "r", stdin);
//	freopen("money.out", "w", stdout);
	memset(money, 0, sizeof(money));
	string biggest;int index;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> stu[i] >> fina[i] >> clas[i] >> ganbu[i] >> west[i] >> article[i];
	for(i = 0;i<n;i++) {
		if(fina[i] > 80 && article[i] >= 1) {
			money[i] += 8000;
		}
		if(fina[i] > 85 && clas[i] > 80) {
			money[i] += 4000;
		}
		if(fina[i] > 90) {
			money[i] += 2000;
		}
		if(fina[i] > 85 && west[i] == 'Y') {
			money[i] += 1000;
		}
		if(clas[i] > 80 && ganbu[i] == 'Y') {
			money[i] += 850;
		}
		if(maxx < money[i]) {
			biggest = stu[i];
			maxx = money[i];
			index = i;
			total = 1;
		}
		else if(maxx == money[i]) {
			total++;
		}
	}
	cout << biggest << endl << money[index] << endl << 1ll * total * money[index] ;
	return 0;
}
