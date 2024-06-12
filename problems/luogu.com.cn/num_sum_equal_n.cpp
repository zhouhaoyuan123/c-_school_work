#include <iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    for(long long i = n;i>=2;i--) {
        if((1 + i) * i / 2 > n) {
            continue;
        }
        long long sum = n * 2 / i;
        long a = (sum - i + 1) / 2;
        long long b = sum - a;
        if(a<b && b - a + 1 == i && (a + b) * i / 2 == n) {
            cout << a << " "<<b<<endl;
        }
    }
    return 0;
}