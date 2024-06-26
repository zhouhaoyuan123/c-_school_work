#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int ans = 5;
        cin>>s;
        sort(s.begin(),s.end(),greater<char>());
        if(s[0] >= '0' && s[0] <= '1') {
            ans = 1;
        }
        else if(s[0] >= '0' && s[0] <= '7') {
            ans = 2;
        }
        else if(s[0] >= '0' && s[0] <= '9') {
            ans = 3;
        }
        else if (s[0] >= '0' && s[0] <= 'F') {
            ans = 4;
        }
        for(int i = 1;i<=4;i++) {
            if(i >= ans) {
                cout << 1<<" ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}