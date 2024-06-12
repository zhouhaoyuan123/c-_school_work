#include <iostream>
using namespace std;

int main() {
    int index = 0,maxn = 0;
    for(int i = 1;i<=7;i++) {
        int t1,t2;
        cin>>t1>>t2;
        if(t1 + t2 > 8) {
            if(maxn < t1 + t2) {
                maxn = t1 + t2;
                index = i;
            } 
        }
    }
    cout << index;
    return 0;
}