#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if(b *b - 4 * a * c < 0) {
        cout << "NO"<<endl;
        return 0;
    }
    
    return 0;
}