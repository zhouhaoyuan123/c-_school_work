#include <iostream>
#include <string>
using namespace std;
int cnt[30];

int main() {
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++) {
        cnt[s[i] - 'a'] ++;
    }
    int minn = 1005,maxn = 0;
    for(int i = 0;i<=25;i++) {
        if(cnt[i]) {
            minn = min(minn,cnt[i]);
            maxn = max(maxn,cnt[i]);
        }
    }
    int res = maxn - minn;
    if(res < 2) {
        cout << "No Answer"<<endl << 0<<endl;
        return 0;
    }
    for(int i = 2;i * i <= res;i++) {
        if(res % i == 0) {
            cout << "No Answer"<<endl << 0<<endl;
            return 0;
        }
    }
    cout << "Lucky Word"<<endl<<res<<endl;
    return 0;
}