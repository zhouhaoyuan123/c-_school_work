#include <iostream>
using namespace std;

int main() {
    int space = 2;
    for(int i = 1;i<=3;i++) {
        for(int j = 1;j<=space;j++) {
            cout << " ";
        }
        for(int j = 1;j<=2 * i - 1;j++) {
            cout << "*";
        }
        space --;
        cout << endl;
    }
    space = 1;
    for(int i = 2;i>=1;i--) {
        for(int j = 1;j<=space;j++) {
            cout << " ";
        }
        for(int j = 1;j<=2 * i - 1;j++) {
            cout << "*";
        }
        space ++;
        cout << endl;
    }
    return 0;
}