#include <iostream>
using namespace std;

struct  Node {
	int data;
	int parent;
	int next;
};
Node table[1000005];

int main() {
	int n, n1 = 0;
	cin >> n;
	Node f;
	f.data = 1;
	f.parent = -1;
	f.next = -1;
	table[1] = f;
	n1++;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		int x = 0, y = 0;
		switch (op) {
			case 1:
				cin >> x >> y;
				Node t;
				t.data = y;
				t.parent = x;
				t.next = table[x].next;
				table[y] = t;
				n1++;
				table[x].next = y;
				//cin,[]
				break;
			case 2:
				cin >> x;
				if (table[x].next == -1) {
					cout << 0 << endl;
				} else {
					cout << table[table[x].next].data << endl;
				}
				break;
			case 3:
				cin >> x;
				table[x].next = table[table[x].next].next;
				n1--;
				break;

		}
	}
	return 0;
}