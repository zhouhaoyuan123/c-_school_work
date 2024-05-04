#include <iostream>
#include <algorithm>
using namespace std;
int school[100005];
//int student[100005];
int search(int num[],int l,int r,int target) {
	while(l < r) {
		int mid = (l + r) / 2;
		//ans = mid;
		if(l + 1 == r) {
			return min(abs(num[l] - target),abs(num[r] - target));	
		}
		if(num[mid] < target) {
			l = mid;
		}
		else if(num[mid] > target){
			r = mid;
		}
		else {
			return 0;
		}
	}
	return -1;
}

int main() {
	int m,n;
	cin>>m>>n;
	for(int i = 1;i<=m;i++) {
		cin>>school[i];
	}
	sort(school + 1,school + 1 + n);
	long long ans = 0;
	while(n --) {
		int stu;
		cin>>stu;
		ans += search(school,1,m,stu);
	}
	cout << ans;
	return 0;
}
