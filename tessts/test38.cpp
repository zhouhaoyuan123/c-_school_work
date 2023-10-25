#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string num[35];
string maxn = "";
int indexn = 0;

int main() {
//	freopen("vote.in", "r", stdin);
//	freopen("vote.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if(num[i] > maxn) {
			maxn = num[i];
			indexn = i; 
		}
	}
	cout <<indexn<<endl<<maxn;
	return 0;
}
