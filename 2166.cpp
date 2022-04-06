//2022_04_05 ��������Ǯ��
//2166 �ٰ����� ����

//1. �ݽð���� ������ �� �������� x�� y�� ����Ʈ�� �����ϰ� ù �������� �ϳ� �� �߰�
//2. �� �������� x��ǥ�� ���� �������� y���� ���ϰ� �� ����� ���Ѵ�.
//3. �� �������� y��ǥ�� ���� �������� x���� ���ϰ� ���Ѵ�.
//4. �ι�° ����� ù��° ������� ���� 2�� ������ ��!
#include <bits/stdc++.h>

using namespace std;

int main() {
	//������� N���� ���� �־����� ������ �ݴ�� �ϸ� �ݽð� ���� ����
	int n;
	cin >> n;
	vector<pair<long long, long long>> points;
	for (int i = 0; i < n; ++i) {
		long long x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	//����Ʈ�� ������ ù �������� �� �ڿ� �߰�
	reverse(points.begin(), points.end());
	points.push_back(points.front());

	double xToy = 0;
	double yTox = 0;
	for (int i = 0; i < n; ++i) {
		xToy += points[i].first * points[i + 1].second;
		yTox += points[i].second * points[i + 1].first;
	}

	double result = (double)(xToy - yTox) / 2;
 	cout <<fixed<<setprecision(1)<< (round(result * 10)) / 10;
}