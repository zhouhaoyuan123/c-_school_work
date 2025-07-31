#include <iostream>
#include <map>
#include <cmath>
using namespace std;
string input[8];
string zodiac[12] = {"Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey",
"Rooster","Dog","Pig","Rat"
};
int detect(string num) {
	for(int i = 0;i<12;i++) {
		if(num == zodiac[i]) return i; 
	}
	return -1;
}
map<string,int> age;
map<string,string> year;

int main() {
	int N;
	cin>>N;
	age["Bessie"] = 0;
	year["Bessie"] = "Ox";
	for(int i = 1;i<=N;i++) {
		for(int j = 0;j<8;j++) {
			cin>>input[j];
		}
		string a = input[0],b = input[7];
		year[a] = input[4];
		if(input[3] == "previous") {
			int dis = detect(year[b]) - detect(year[a]);
			if(dis <= 0) dis += 12;
			age[a] = age[b] - dis;
		}
		else {
			int dis = detect(year[a]) - detect(year[b]);
			if(dis <= 0) dis += 12;
			age[a] = age[b] + dis;
		}
	}
	cout << abs(age["Elsie"]) << endl;
	return 0;
}
