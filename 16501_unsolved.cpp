//2022_03_25 ��������Ǯ��
//16501 ������ ����

//����Ž���ϱ�? ���� ����س��� ���� ����
//12, 34 == 34,12 �� ������ ã�� ��
//���ĵǾ��ִ� ���ո� ã���� ��
//8���� ���ڰ� �� ���Ǿ���ϱ� ������ 1�� ���� �տ� �ִ� ��츸 Ž���ϸ� ��
//������ �� ��...���� �� �� �������� �غ��� 20:49��
double ability[8][8];
bool played[8];

#include <bits/stdc++.h>

using namespace std;

int main() {
	for (int i = 0; i < 8; ++i)
			cin >> ability[i][i];

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			ability[i][j] = (ability[i][i] + ability[j][j]) / 2;
			ability[j][i] = ability[i][j];
		}
	return 0;
}