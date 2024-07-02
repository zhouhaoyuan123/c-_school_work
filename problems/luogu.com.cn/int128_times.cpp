#include <iostream>
#include <cstdio>
using namespace std;
__int128 read() {
    __int128 n = 0;
    char num = getchar();
    while(num >= '0' && num <= '9') {
        n = n * 10 + (__int128)(num - '0');
        num = getchar();
    }
    return n;
}
void write(__int128 n) {
    if(n <= 9) {
        putchar(char(int(n) + '0'));
        return;
    }
    write(n / 10);
    putchar(char(int(n % 10) + '0'));
}

int main() {
    __int128 a = read();
    __int128 b = read();
    __int128 p = read();
    write(a * b % p);
    return 0;
}