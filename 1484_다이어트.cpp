//2022_04_13 ��������Ǯ��
//1484�� ���̾�Ʈ

//�ð� 2��, �޸� 128MB
//�Է� 10��
//x2 - y2 = G;
//x2 - (x-1)2 <= G�� ���� Ȯ���ϸ� ��
//��ǥ: ������ ���� ��� ���� ������ - ����� ��
#include <bits/stdc++.h>

using namespace std;

int main() {
	int G;
	cin >> G;
	int x = ceil(sqrt((double)G));
	int y = 0;
	double realy = 0.0;
	int total = 0;
	while (x <= (G + 1)/2)
	{
		//y�� �ڿ����� ��
		y = realy = sqrt(pow(x, 2) - G);
		if (y == realy && y != 0) {
			cout << x << '\n';
			total++;
		}
		x++;
	}
	if (total == 0)
		cout << -1;
}