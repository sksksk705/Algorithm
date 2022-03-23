//2022_03_23 ��������Ǯ��
//14718 �밨�� ��� ����

//17:12���� �� ���� ���� � �������� ������, ��Ž���� ����
//17:42 ���� ���� �� �̱�� �� �ƴ϶� ��ü�� �� ���ƾ� �̱� �� ����.
//�հ谡 �����鼭 ������ ���� ����������.
//18:26�� �ð��ʰ�

//���̵��1: �ᱹ�� ���� ū ���� �ǳʶٰ� ���� ��.�հ谡 ���� ���� ����� �ǳʶٸ� ���� ���ñ�?
//18:37�� ����
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, k;

int soldier[100][3];
int cache[101][3][100];

//���� Ž��
int leastStatPoint(int idx, int pass)
{
	if (idx > n)
	{
		if (pass > 0)
			return INF;
		int result = 0;
		for (int i = 0; i < 3; ++i) {
			//�н��� �ϰ� �� ���� ���� ���� ���̴�.
			result += cache[idx-1][i][0];
		}
		return result;
	}

	for (int i = 0; i < 3; ++i) {
		int pstat;
		int nstat;
		pstat = cache[idx-1][i][pass];
		nstat = soldier[idx-1][i];
		cache[idx][i][pass] = max(pstat, nstat);
		if(pass > 0)
			cache[idx][i][pass-1] = pstat;
	}
	if (pass > 0)
		return min(leastStatPoint(idx+1, pass - 1), leastStatPoint(idx+1, pass));
	return leastStatPoint(idx+1, pass);
}


int main() {

	cin >> n >> k;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) {
			cin >> soldier[i][j];
			sum += soldier[i][j];
		}
		vec.push_back(make_pair(sum, i));
	}

	//�հ������ �����ؼ� ���� ���� ���� ���� �����Ѵ�.
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n - k; ++i)
		vec.pop_back();

	int str = 0, dex = 0, intel = 0;
	//���� ����� ���� ���� ���� ������ ������ ���ȿ� �����Ѵ�.
	for (auto sol : vec)
	{
		str = max(str, soldier[sol.second][0]);
		dex = max(dex, soldier[sol.second][1]);
		intel = max(intel, soldier[sol.second][2]);
	}

	cout << str + dex + intel;
	//cout << leastStatPoint(1, n - k);
}