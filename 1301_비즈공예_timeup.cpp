//2022_04_30 ��������Ǯ��
//1301�� �������

//����� ���� ����� ��� ����Ž�� ������ �� ����
//����Ž������ �ٰ������� �ð��ʰ��� ����� - �޸���ƽ���� ���ҽ��Ѻ���?
#include <bits/stdc++.h>

using namespace std;

//�� ������ ��ü ������ 1/3 �̻��̸� ���� �� ����.
bool simpleHeuristic(const vector<int>& bizs) {
	double total = 0;
	for (auto amount : bizs) {
		total += amount;
	}
	int possible = ceil(total / 3);
	for (auto amount : bizs) {
		if (amount > possible)
			return false;
	}
	return true;
}

//����Ž�� - �ð��ʰ� - �޸���ƽ �߰� - �׷����� �ð��ʰ�
int bizArt(int spices, int pprev, int prev, vector<int>& bizs) {
	int ret = 0;
	//�޸���ƽ �߰�
	if (!simpleHeuristic(bizs))
		return ret = 0;
	bool usedAll = true;
	for (int color = 0; color < spices; ++color) {
		if (bizs[color] > 0)
			usedAll = false;
		if (bizs[color] > 0 && color != pprev && color != prev)
		{
			bizs[color]--;
			ret += bizArt(spices, prev, color, bizs);
			bizs[color]++;
		}
	}
	if (usedAll)
		return 1;
	return ret;
}


int main() {
	int n;
	cin >> n;
	vector<int> bizs(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> bizs[i];
	}
	int result = bizArt(n, -1, -1, bizs);
	cout << result;
}