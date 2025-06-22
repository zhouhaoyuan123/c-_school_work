#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T --) {
		int n;
		string s;
		cin>>n;
		cin>>s;
		bool flag = 0;
		for(int i = 0;i<n - 1;i++) {
			if(s[i] > s[i + 1]) {
				flag = 1;
				for(int j = i;j<n - 1;j++) {
					if(!(s[j] > s[j + 1])) break;
					swap(s[j],s[j + 1]);
				}
				break;
			}
		}
		if(!flag) {
			swap(s[max(n - 2,0)],s[n - 1]);
		}
		cout << s << endl;
	}
	return 0;
}
