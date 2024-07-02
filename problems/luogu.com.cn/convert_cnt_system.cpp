#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int convert_to_dec(int n,string s) {
    int p = 0,ans = 0;
    int mode = 1;
    for(int i = s.size() - 1;i>=0;i--) {
        if(s[i] >='0' &&  s[i] <= '9') {
            ans += (mode * (s[i] - '0') * pow(n,p));
            p++;
        }
        else if(s[i] == '-') {
            mode = -1;
        }
        else {
            ans += (mode * (s[i] - 'A' + 10) * pow(n,p));
            p++;
        }
    }
    return ans;
}
string convert_to_other(int m,int num) {
    string s = "";
    while(num) {
        if(num % m >= 0 && num % m <= 9) {
            s.insert(0,1,char(num % m + '0'));
        }
        else {
            s.insert(0,1,char(num % m - 10 + 'A'));
        }
        num /= m;
    }
    return s;
}

int main() {
    int n;
    string s;
    int m;
    cin>>n>>s>>m;
    //cout << convert_to_dec(n,s) <<endl;
    cout << convert_to_other(m,convert_to_dec(n,s))<<endl;
    return 0;
}