//2022_03_26 ������ȹ��
//5569 ��ٰ��

//���࿡ ���� ��ȹ���� �ƴϾ��ٸ� BFS�� Ǯ��������?
//��ȭ���� ����� �� ���� ����ؼ� ����Ž������ Ǯ�� �ִµ� �Լ��� �ʹ� ������...
#include <bits/stdc++.h>

const int MOD = 100000;
using namespace std;
int w, h;
int dx[2]{ 0,1 };
int dy[2]{ 1,0 };
int cache[101][101][2][2];

int getPath(int x, int y, bool rotated, bool direction)
{
	//�������1: �����ʰ�
	if (x > w || y > h)
		return 0;
	//�������2: ����
	if (x == w && y == h)
		return 1;
	int& ret = cache[y][x][rotated][direction];
	if (ret != -1)
		return ret;
	int nextx, nexty;

	//�� ���� ������ �ٲ�ٸ� �� ���� �״�� ����
	if (rotated) {
		nextx = x + dx[direction];
		nexty = y + dy[direction];
		ret = getPath(nextx, nexty, false, direction) % MOD;
		ret %= MOD;
	}
	else {
		//�������̶�� ������, �Ʒ� ��������̴� �� �� �ִ�.
		if (x == 1 && y == 1) {
			ret = (getPath(x + dx[direction], y + dy[direction], false, direction) +
				getPath(x + dx[!direction], y + dy[!direction], false, !direction)) % MOD;
		}
		//�� �ܴ� ���� ������ ���ų� ������ �ٲٰų� �� �� �ִ�.
		else {
			ret = (getPath(x + dx[direction], y + dy[direction], false, direction) +
				getPath(x + dx[!direction], y + dy[!direction], true, !direction)) % MOD;
		}
		ret %= MOD;
	}
	return ret;
}

int main() {
	cin >> w >> h;
	memset(cache, -1, sizeof(cache));
	cout << getPath(1, 1, false, true);
}