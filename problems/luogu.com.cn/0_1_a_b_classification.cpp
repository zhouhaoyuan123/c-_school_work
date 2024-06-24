#include <iostream>
using namespace std;
int suma = 0,sumb = 0;
void calc(int n) {
    while(n) {
        if(n % 2 == 0) {
            suma ++;
        }
        else {
            sumb ++;
        }
        n /= 2;
    }
}

int main() {
    int n;
    cin>>n;
    int cnt = 0,cnt2 = 0;
    for(int i = 1;i<=n;i++) {
        suma = 0,sumb = 0;
        calc(i);
        if(sumb > suma) {
            cnt++;
        }
        else {
            cnt2 ++;
        }
    }
    cout << cnt<<" "<<cnt2;
    return 0;
}