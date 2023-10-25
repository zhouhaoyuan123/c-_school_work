#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n % 10);
		n /= 10;
	}
	return ans;
}

bool cmp(vector<int> x, vector<int> y) {
	if (x.size() == y.size()) {
		if (x.size() == 0) {
			return true;
		}
		cout << x.size() << " " << y.size() << endl;
		return sum(x[0]) < sum(y[0]);
	}
	return x.size() > y.size();
}

int main(

) {
	//return 0;
	int n;
	cin >> n;
	//return 0;
	vector<int> v[60];
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v[sum(t)].push_back(t);
	}
	//return 0;
	sort(v, v + 54, cmp);
	return 0;
	cout << sum(v[0][0]) << endl;
	return 0;
	sort(v[0].begin(), v[0].end(), greater<int>());
	for (int i = 0; i < v[0].size(); i++) {
		cout << v[0][i] << " ";
	}
	return 0;
}