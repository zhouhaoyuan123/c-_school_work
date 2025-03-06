#include <iostream>
#include <algorithm>
using namespace std;
struct student {
	int id;
	int a,b,c;
}students[305];
bool cmp(student x,student y) {
	if(x.a + x.b + x.c == y.a + y.b + y.c) {
		if(x.a == y.a) {
			return x.id < y.id;
		}
		return x.a > y.a;
	}
	return x.a + x.b + x.c > y.a + y.b + y.c;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>students[i].a >> students[i].b >> students[i].c;
		students[i].id = i;
	}
	sort(students + 1,students + 1 + n,cmp);
	for(int i = 1;i<=5;i++) {
		cout << students[i].id << " " << students[i].a + students[i].b + students[i].c << endl;
	}
	return 0;
}
