#include <iostream>
using namespace std;
long long num[200005];
long long sum[200005];

int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
    }
    long long tmp = -1e11 ,last = 1;
    for(int i = 1;i<=n;i++) {
        sum[i] = max(sum[i - 1] + num[i],num[i]);
        tmp = max(tmp,sum[i]);
    }
    cout << tmp;
    return 0;
}