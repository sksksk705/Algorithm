//2022_03_26 ������ȹ��
//2281 ������Ʈ: ����ȭ���� 19:49

//�Ǽ�1: ������ �����ε� ������� �ع���
//20:47�� ����
#include <bits/stdc++.h>

using namespace std;

int cache[1000][1001];
int name[1000];
const int INF = 987654321;

int n, m;

int deathNote(int idx, int sum)
{
	//�������1: ��� �̸��� �� ��ٸ� 0�� ��ȯ
	if (idx >= n)
		return 0;

	//�������2: �� ���� ������ �� ��ٸ� ���� �ٿ� ����.
	if (sum > m)
		return deathNote(idx+1, name[idx] + 1);

	int& ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = INF;
	if (name[idx] <=  m - sum)
	{
		ret = min(ret, deathNote(idx + 1, sum + name[idx] + 1));
	}
	ret = min(ret, deathNote(idx + 1, name[idx] + 1) + (int)pow(m - sum + 1, 2));
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> name[i];
	}
	memset(cache, -1, sizeof(cache));

	cout << deathNote(0,0);
	return 0;
}