#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int k;
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	cin>>k;
	//i相当于x
	for(int i = k+1;i<=2*k;i++) {
		double tmp = round(1/(1.0/k-1.0/i)*100)/100;//1/j->j
		int t2 = tmp;//j
		if(t2-tmp == 0.0) {//判断是不是整数
			cout<<i<<":"<<t2<<endl;
		}
	}
	fclose(stdin);

	fclose(stdout);
	return 0;
}
