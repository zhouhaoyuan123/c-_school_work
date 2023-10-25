#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, draw = 1; //����,�������
	cin >> n;
	vector<int> v[n];//ͼ�ξ���
	int spaces = n - 1;//�ո����
	for (int i = 0; i < n; i++) { //��ѭ��
		for (int j = 0; j < spaces; j++) { //�ո�
			cout << " ";
		}
		for (int j = 0; j < draw; j++) {
			if (j == 0 || j == draw - 1) {
				v[i].push_back(1);
			} else {
				v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]); //�������
				/*
					1
				  1	   1->j -> j+1
				 1  2   1

				*/
			}
			cout << v[i][j] << " ";
		}
		draw++;
		spaces--;//��������
		cout << endl;
	}
	return 0;
}