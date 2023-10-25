#include <set>
#include <cstdio>
using namespace std;

int main() {
	//freopen("minus.in", "r", stdin);
	//freopen("minus.out", "w", stdout);
	long long n, k; //个数，目标
	scanf("%lld %lld", &n, &k);
	multiset<long long> s;
	for (long long i = 0; i < n; i++) { //输入
		long long t;
		scanf("%lld", &t);
		s.insert(t);
	}
	long long cnt  = 0;//可能性
	for (auto &it : s) {
		if ((s.count(it - k) && (it - k) > it) ) { //检测符合要求的数值在不在
			cnt += s.count(it - k);
		}
		if (s.count(k + it) && (k + it) > it) {
			cnt += s.count(it + k);
		}
	}
	printf("%lld", cnt);
	return 0;
}