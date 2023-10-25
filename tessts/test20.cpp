#include <iostream>
#include <string>
using namespace std;
char s[105];

int main() {
	string str;
	cin >> str;
	int top = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'J') { //金钩
			if (top == 0) { //五卡牌
				s[top] = 'J';
				top++;
			} else {
				top = 0;
				str.replace(0, i + 1, "");
				i = -1;
			}
//			for (int i = 0; i < top; i++) {
//				cout << s[i] << " ";
//			}
//			cout << endl;
		} else {
			if (str.find(str[i]) != i && str.find(str[i]) < i) { //有相同的扑克牌
				top -= i - str.find(str[i]);
				int tmp = i;
				i -= i - str.find(str[i])  + 1;
				str.replace(str.find(str[tmp]), tmp - str.find(str[tmp])  + 1, "");

			} else {
				s[top] = str[i];
//				for (int i = 0; i <= top; i++) {
//					cout << s[i] << " ";
//				}
				//cout << endl;
				top++;
			}
//			for (int i = 0; i < top; i++) {
//				cout << s[i] << " ";
//			}
//			cout << endl;
		}
	}
	for (int i = 0; i < top; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}