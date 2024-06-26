#include <iostream>
#include <cmath>
using namespace std;
bool vis[100005];

int main() {
    long long n;
    cin>>n;
    for(int i = 2;i<=sqrt(n);i++) {
        if(!vis[i]) {
            if(n % i == 0) {
                cout << n / i <<endl;
                return 0;
            }
            for(int j = i;j<= sqrt(n);j+=i) {
                vis[j] = 1;
            }
        }
    }
    return 0;
}