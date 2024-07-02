#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    //a * b / gcd = lcm
    //y = a * b / x
    //a * b = x * y
    int ans = 0;
    for(int i = x;i <= y;i++) { //a -> i
        if(1ll * x * y % i == 0) {
            long long res = 1ll * x * y / i;
            long long res2 = __gcd(1ll * i,res);
            if(res >= x && res <= y && res2 == x && i * res / res2 == y) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}