#include <iostream>
#include <algorithm>
using namespace std;
struct rect {
	int x1,y1,x2,y2;
}rects[105];
bool cmp(rect x,rect y) {
	return (x.x2 - x.x1) * (x.y2 - x.y1) < (y.x2 - y.x1) * (y.y2 - y.y1);
}
bool inrect(int x,int y,rect r) {
	return r.x1 <= x && x <= r.x2 && r.y1 <= y && y <= r.y2; 
}

int main() {
	int h,w,n;
	cin>>w>>h>>n;
	int cnt = 0;
	rects[++cnt] = {0,0,w,h};
	for(int i = 1;i<=n;i++) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j = 1;j<=cnt;j++) {
			if(inrect(x1,y1,rects[j]) && inrect(x2,y2,rects[j])) {
				rects[++cnt] = {rects[j].x1,rects[j].y1,x2,y2};
				rects[j] = {x1,y1,rects[j].x2,rects[j].y2};
				break;
			}
		}
	}
	sort(rects+1,rects+1+cnt,cmp);
	for(int i = 1;i<=n+1;i++) cout << (rects[i].x2 - rects[i].x1) * (rects[i].y2 - rects[i].y1) << " ";
	cout << endl;
	return 0;
}
