#include <iostream>
using namespace std;

int main() {
	string song,input;
	cin>>song>>input;
	int index = -1;
	int ans = 0;
	for(int i = 0;i<input.size();i++) {
		if(index >= song.find(input[i])) {
			ans ++;
			index = song.find(input[i]);
		}
		else {
			index = song.find(input[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
