#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cache[3000005];

int main() {
	int n;
	long long p;
	scanf("%d%lld",&n,&p);
//	init(n);
	cache[1] = 1;
	printf("%d\n",1);
	for(int i = 2;i<=n;i++) {
		cache[i] = (p - p / i) * cache[p % i] % p;
		printf("%d\n",cache[i]);
	}
	return 0;
}
