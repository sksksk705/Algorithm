//2022_04_21 ��������Ǯ��
//13904�� ����

//��� ������ �� ���ϱ��� �� �� ���� �� ��Ž�� �ð� ���⵵ O(N!)
//������ �� ������ ���� ���� ������ �ֱ� ������ �κй����� �� �ȴ�.
//�׸���� �ذ��ϴ� ���� ������ �� ������ ������ ��� �ұ�?
//���� ���� �ָ� �����ұ�? �׷� 1������ 2���� �϶� �� ���� ����..
//�Ųٷ� �ϸ� �� �� ����. ������ ������ �� �� �ִ� �� �߿� ���� ���� ������ �ϸ� �� ��.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	//�� 1000���� ���� �� ������ ������ �˳��� ������ ��.
	vector<vector<int>> task(1001);
	int lastday = 0;
	for (int i = 0; i < n; ++i)
	{
		int day, point;
		cin >> day >> point;
		task[day].push_back(point);
		lastday = max(day, lastday);
	}
	priority_queue<int> pq;

	int result = 0;
	for (int i = lastday; i > 0; --i)
	{
		for (auto point : task[i])
			pq.push(point);

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}