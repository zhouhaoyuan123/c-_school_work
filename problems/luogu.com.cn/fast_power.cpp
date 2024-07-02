#include <iostream>
using namespace std;

int main() {
    long long a,b,p;
    cin>>a>>b>>p;
    long long ans = 1;
    long long buf = a;
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
    cout << a<<"^"<<b<<" mod "<<p<<"="<<ans * buf % p;
    return 0;
}