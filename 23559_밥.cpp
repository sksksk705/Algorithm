//2022_04_07 ��������Ǯ��
//23559 ��

//1000������ ������ �Ǵ� 5,1�� �޴�����;
//N�� 10�� X�� �ִ� 5��, ���� �ʹ� ũ�ϱ� �׸��� ����� �� 
//1000���� ������ ���� �� �ִ�. �� 5000��¥���� 5000���̻��� ���� ���� �� �ִ�.
//1000�� ��� 5000���� ������ 4000���� �� ������. ���� 4000���� ����ŭ ���̰� ū �ֵ��� ����
//1000���� �� ������ ���� 1000���� ����
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return (p1.first - p1.second > p2.first - p2.second);
}

int main() {
	int n, x;
	cin >> n >> x;
	x /= 1000;
	
	vector<pair<int, int>> food;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		int A, B;
		cin >> A >> B;
		total += B;
		food.push_back(make_pair(A, B));
	}

	sort(food.begin(), food.end(), cmp);
	int canEatA = (x - n) / 4;
	for (int i = 0; i < canEatA; ++i) {
		if (food[i].first <= food[i].second)
			break;
		total -= food[i].second;
		total += food[i].first;
	}
	cout << total;

}