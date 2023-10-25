#include <iostream>
#include <iomanip>
#include <cstring>
#include <malloc.h>
using namespace std;

struct G {
	int data;
	int ad;
	G *next;
};

struct h {
	int data;
	G *fe;
} h[101];

int main() {
	int m = 5, n = 4;
	//初始化表头
	for (int i = 1; i <= m; i++) {
		h[i].data = i;
		h[i].fe = NULL;
	}
	int x, y;
	G *g;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		g = (G *)malloc(sizeof(g));
		g->ad = y;
		g->next = h[x].fe;
		h[x].fe = g;
		g = (G *)malloc(sizeof(g));
		g->ad = x;
		g->next = h[y].fe;
		h[y].fe = g;
	}
	return 0;
}