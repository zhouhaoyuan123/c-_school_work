#include <string>
#include <iostream>
using namespace std;

int sum(string s) {//��ͺ���
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans += (s[i] - '0');
	}
	return ans;
}

int sum(int s) {//��ͺ���
	int ans = 0;
	while (s > 0) {
		ans += s % 10;
		s /= 10;
	}
	return ans;
}

int main() {
	//����
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string num;//����
		cin >> num;
		for (int j = num.size() - 1, cnt = 1; j >= 0; j--, cnt++) {
			if (cnt % 2 == 0) { //ż��
				continue;
			}
			if ((num[j] - '0') * 7 > 9) {
				int tmp = sum((num[j] - '0') * 7);//��¼��
				while (true) { //ֱ��<=9
					if (tmp > 9) {
						tmp = sum(tmp);
					} else {
						num[j] = tmp + '0';
						break;
					}
				}
			} else {
				num[j] = (num[j] - '0') * 7 + '0';
			}

		}
		if (sum(num) % 8 == 0) {
			cout << "T" << endl;
		} else {
			cout << "F" << endl;
		}
	}
	return 0;
}