#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    long long n;
    cin>>n;
    bool flag = 1;
    for(int i = 2;1ll * i*i<=n;i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt ++;
            }
            if(flag) {
                flag = 0;
                if(cnt > 1) 
                    cout << i <<"^" << cnt;
                else
                    cout << i;
            }
            else {
                if(cnt > 1) 
                    cout << " * " << i <<"^" << cnt;
                else
                    cout << " * "<<i;
            }
        }
    }
    if(n > 1) {
        if(flag) {
            cout << n;
        }
        else {
            cout <<" * "<<n;
        }
    }
    cout << endl;
    return 0;
}