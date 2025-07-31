#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int A;
long long N;
long long ans;
bool check(int A,long long num) {
	if(num > N) return false;
	string tmp = "";
	while(num) {
		tmp += ((num % A) - '0');
		num /= A;
	}
	string tmp2 = tmp;
	reverse(tmp2.begin(),tmp2.end());
	if(tmp2 == tmp) {
		return true;
	}
	return false;
}

int main() {
	cin>>A>>N;
	for(int i = 1;i<=1e6;i++) {
		string tmp = "";
		int j = i;
		while(i) {
			tmp += (i % 10) + '0';
			i /= 10;
		}
		i = j;
		string tmp2 = tmp;
		reverse(tmp2.begin(),tmp2.end());
		tmp2 += tmp;
		if(check(A,stoll(tmp2))) ans += stoll(tmp2);
		tmp2 = tmp;
		tmp2.replace(0,1,"");
		reverse(tmp2.begin(),tmp2.end());
		tmp2 += tmp;
		if(check(A,stoll(tmp2))) ans += stoll(tmp2);
	}
	cout << ans << endl;
	return 0;
}
