#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int num[10];

int main() {
    int n = 9;
    int ar,br,cr;
    cin>>ar>>br>>cr;
    if(ar == 0) {
        cout << "No!!!";
        return 0;
    }
    for(int i = 1;i <= n;i++) {
        num[i] = i;
    }
    bool flag = false;
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
        int tmp = a;
        if(tmp % ar == 0 &&tmp / ar * br == b && tmp / ar * cr == c) {
            flag = false;
            cout << a << " "<< b << " "<<c << endl;
        }
    }while(next_permutation(num+1,num+1+n));
    if(flag) {
        cout << "No!!!";
    }
    return 0;
}