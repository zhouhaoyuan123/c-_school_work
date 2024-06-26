#include <iostream>
using namespace std;
bool vis[10005];

int main() {
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++) {
        if(!vis[i]) {
            for(int j = i * 2;j<=n;j+=i) {
                vis[j] = 1;
            }
        }
    }
    vis[0] = 1;
    vis[1] = 1;
    for(int i = 4;i<=n;i+=2) {
        cout << i<<"=";
        for(int j = 2;j<=i;j++) {
            if(i - j < j) {
                cout << endl;
                break;
            }
            if((!vis[j]) && (!vis[i - j])) {
                cout << j << "+"<<i - j<<endl;
                break;
            }
        }
    }
    return 0;
}