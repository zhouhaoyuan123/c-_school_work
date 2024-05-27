#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int num[10];

int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        num[i] = i;
    }
    do {
        for(int i = 1;i<=n;i++) {
            cout << setw(5)<<num[i];
        }
        cout << endl;
    }while(next_permutation(num+1,num+1+n));
    return 0;
}