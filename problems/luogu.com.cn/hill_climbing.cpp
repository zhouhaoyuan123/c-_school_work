#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct point {
	double x,y,z;
}site[50005];
bool cmp(point x,point y) {
	return x.z < y.z;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>site[i].x >> site[i].y >> site[i].z;
	}
	sort(site+1,site+1+n,cmp);
	double ans = 0;
	for(int i = 2;i<=n;i++) {
		ans += sqrt((site[i].x - site[i - 1].x) * (site[i].x - site[i - 1].x) + (site[i].y - site[i - 1].y)*(site[i].y - site[i - 1].y)+(site[i].z - site[i - 1].z)*(site[i].z - site[i - 1].z));
	}
	cout << fixed << setprecision(3)<<ans;
	return 0;
}
