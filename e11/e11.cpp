#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct pixel {
	int id;
	int cnt;
	bool is_sixteen;
};
int n;
string s;
int num[20][20];

bool cmp(pixel x, pixel y) {
	if (x.cnt == y.cnt) {
		return x.id < y.id;
	}
	return x.cnt > y.cnt;
}

bool cmp2(pixel x, pixel y) {
	if (x.id == y.id) {
		return true;
	}
	return x.id < y.id;
}

void mul_num(int l) {
	for (int i = 0, cnt = 0; i < s.size(); i += 2, cnt++) {
		string tmp = s.substr(i, 2);
		int t2 = 0, t3 = 1;
		for (int j = tmp.size() - 1; j >= 0; j--) {
			if (tmp[j] >= '0' && tmp[j] <= '9') {
				t2 += (tmp[j] - '0') * t3;
			} else {
				t2 += (tmp[j] - 'A' + 10) * t3;
			}
			t3 *= 16;
		}
		num[l][cnt] = t2;
	}
}

void to_hex(int n) {
	string ans;
	bool flag = true;
	while (n > 0) {
		flag = false;
		int t = n % 16;
		if (t > 9) {
			t -= 10;
			ans += (t + 'A');
		} else {
			ans += (t + '0');
		}
		n /= 16;
	}
	if (flag) {
		ans += "0";
	}
	if (ans.size() == 1) {
		cout << 0;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}

void to_hex2(int n) {
	string ans;
	bool flag = true;
	while (n > 0) {
		flag = false;
		int t = n % 16;
		if (t > 9) {
			t -= 10;
			ans += (t + 'A');
		} else {
			ans += (t + '0');
		}
		n /= 16;
	}
	if (flag) {
		ans += "0";
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}

/*
HEX×ªDECº¯Êý
Í°ÅÅÐò
Ã¶¾Ù
*/
int main() {
	cin >> n;
	vector<pixel> v;
	for (int i = 0; i < 256; i++) {
		pixel t;
		t.id = i;
		t.cnt = 0;
		t.is_sixteen = false;
		v.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		mul_num(i);
		for (int j = 0, cnt1 = 0; j < s.size(); j += 2, cnt1++) {
			v[num[i][cnt1]].cnt++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < 16; i++) {
		to_hex(v[i].id);
		//v[i].id = i;
		v[i].is_sixteen = true;
	}
	cout << endl;

	//cout << v.size() << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0, cnt = 0; j < (s.size() / 2); j++, cnt++) {
			int min = abs(num[i][cnt] - v[0].id);
			int ans = 0;
			for (int x = 0; x < 16; x++) {
				if (min > abs(num[i][cnt] - v[x].id)) {
					min = abs(num[i][cnt] - v[x].id);
					ans = x;
				}
			}
			num[i][cnt] = ans;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0, cnt = 0; j < (s.size() / 2); j++, cnt++) {
			to_hex2(num[i][cnt]);
		}
		cout << endl;
	}
	return 0;
}