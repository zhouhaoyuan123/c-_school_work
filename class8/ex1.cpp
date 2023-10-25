#include <iostream>
#include <map>
using namespace std;

map<char, int> maps;
map<char, int>::iterator it ;

int main() {
	maps['e'] = 99;
	//cout << maps['e'];
	for (it = maps.begin(); it != maps.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	maps.erase(it);
	maps.erase(maps.begin(), maps.end());
	return 0;
}