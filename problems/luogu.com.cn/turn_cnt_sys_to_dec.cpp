#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin>>N;
    for(int i = 1;i<=N;i++) {
        int k;
        string num;
        cin>>k>>num;
        int p = 0;
        long long ans = 0;
        for(int i = num.size() - 1;i>=0;i--) {
            if(num[i] >= '0' && num[i] <= '9') {
                ans += 1ll * (num[i] - '0') * pow(1ll * k,p ++);
            }
            else {
                ans += 1ll * (num[i] - 'A' + 10) * pow (1ll * k,p ++);
            }
        }
        cout << ans << endl;        
    }
    return 0;
}