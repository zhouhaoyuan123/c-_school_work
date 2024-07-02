#include <iostream>
using namespace std;
int fast_pow(long long a,long long b,int mod) {
    long long buf = a;
    int p = mod;
    long long ans = 1;
    for(int i = b;i>1;) {
        if(i % 2 == 0) {
            buf *= buf;
            buf %= p;
            i /= 2;
        }
        else {
            ans *= buf;
            ans %= p;
            i--;
        }
    }
    return ans * buf % p;
}

int main() {
    long long n,m;
    cin>>m>>n;
    long long res = fast_pow(m,n,100003) - 1ll * (m % 100003) * fast_pow(m - 1,n - 1,100003) % 100003;
    if(res < 0) {
        res = 100003 + res;
    }
    cout << res<<endl;
    return 0;
}