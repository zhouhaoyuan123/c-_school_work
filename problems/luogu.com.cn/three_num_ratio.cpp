#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int num[10];

int main() {
    int n = 9;
    for(int i = 1;i <= n;i++) {
        num[i] = i;
    }
    do {
        int a = 0,b = 0,c = 0;
        for(int i = 1;i<=3;i++) {
            a *= 10;
            a += num[i];
        }
        for(int i = 4;i<=6;i++) {
            b *= 10;
            b += num[i];
        }
        for(int i = 7;i<=9;i++) {
            c *= 10;
            c += num[i];
        }
        if(b % a == 0 && b / a == 2 && c % a == 0 && c / a == 3) {
            cout << a << " "<< b << " "<<c << endl;
        }
    }while(next_permutation(num+1,num+1+n));
    return 0;
}