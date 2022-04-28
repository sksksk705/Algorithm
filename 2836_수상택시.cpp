//2022_04_28 ��������Ǯ��
//2836�� �����ý�

//Ÿ�� ���� ������ ������ �տ� �ִ� �� ������� �ʾƵ� �ȴ�. ���� ���� �˾Ƽ� ��
//������ ���� Ÿ�� ������ ���� ��: ��ġ�� ������ �ִٸ� �¿�� �� ������ �̵�.

//m�� �ִ� 10���̱� ������ �Ÿ��� �ִ� 30���� ���� �� ����(int ���� �ʰ�)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; ++i)
	{
		int depart, land;
		cin >> depart >> land;
		//������ ���� Ÿ�� ������ �ڿ� �ִٸ� ������� �ʴ´�.
		if (land >= depart)
			continue;

		//������ ���� �������� �������� ����
		pq.push(pair<int, int>(land, depart));
	}

	//prev: ���� ��ġ
	//pos: ���� ��ġ
	//dist: �̵��� �Ÿ�
	int prev = 0;
	int pos = 0;
	long long dist = 0;
	while (!pq.empty()) {
		pos = pq.top().second;
		dist += pos - prev;
		int toward = pq.top().first;
		pq.pop();
		//������ ��ġ�� ����� �ִٸ� ���� �¿��.
		while (!pq.empty()&&pq.top().first < pos)
		{
			auto nextPerson = pq.top();
			pq.pop();
			//������ġ�� ���� Ÿ�� ��ġ���� ũ�� ������� �ʴ´�.
			if (pos > nextPerson.second)
				continue;

			//���� �¿� ��ġ���� ���� Ÿ�� ��ġ���� �̵�
			prev = pos;
			pos = nextPerson.second;
			dist += pos - prev;
		}
		//������ ��ġ�� ����� �� �¿�� ù��° ����� ������ ��ҷ� ����.
		dist += pos - toward;

		//�� �̻� �鸱 ���� ���ٸ� ���� ������ ������ ����.
		if (pq.empty())
			dist += m - toward;

		prev = toward;
	}

	cout << dist;
}