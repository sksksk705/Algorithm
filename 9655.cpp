//2022_04_05 ���հ���
//9655 ������

//���������� dp�� Ǯ���!
#include <bits/stdc++.h>

using namespace std;

int cache[1001];

bool canWin(int stone) {
	//������ ���� �� ����� ��������;
	if (stone == 0)
		return false;
	int& ret = cache[stone];
	if (ret != -1)
		return ret;
	ret = false;
	if (stone >= 3)
		ret = !canWin(stone - 1) || !canWin(stone - 3);
	else
		ret = !canWin(stone - 1);
	return ret;
}

int main() {
	int stone;
	cin >> stone;
	memset(cache, -1, sizeof(cache));
	if (canWin(stone))
		cout << "SK";
	else
		cout << "CY";
}