//2022_04_15 ������
//1004�� �����

//�� ���� ���������� ���ÿ� �������� �ʴ� ���� ���� ���� �������Ѿ���. XOR
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		double n;
		cin >> n;

		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			bool prince, planet;
			double cx, cy,r;
			cin >> cx>>cy>>r;

			sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r ? prince = true : prince = false;
			sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r ? planet = true : planet = false;

			result += (planet ^ prince);
		}
		cout << result << '\n';
	}

}