//2022_03_26 ������ȹ��
//23560 ��

//���̵��: ��ħ�� ��ħ, ������ ���� �� ����, ������ ���ɸ� �Ա� ����

#include<bits/stdc++.h>

using namespace std;

int cache[15][3][2][2];
int n;

//���� ��¥, ���� �ð�(0 ��ħ, 1 ����, 2 ����), ���� ���� ����(0 ��, 1��) , ������ ���� ����(0 ��, 1��)
int eatPill(int days, int time, int front, int prev)
{
	//�������1: ��� ���� �� �Ծ���.
	if (days >= n)
		return 1;
	int& ret = cache[days][time][front][prev];
	if (ret != -1)
		return ret;
	if (time == 0) {
		//���� ���ɰ� ������ ���� ���� ���� �Ծ��ٸ� ��, �� �ƹ��ų� �������
		if (prev == front)
			ret = eatPill(days, 1, 1, front) + eatPill(days, 1, 1, front);
		//���� ���ɰ� ������ �ٸ� ���� ���� �Ծ��ٸ� ���� ���ɿ� ���� ���� �ۿ� ���� �� ����
		else
			ret = eatPill(days, 1, prev, front);
	}
	if (time == 1) {
		//��ħ�� ���� ���⸸ �Ծ����
		ret = eatPill(days, 2, front, front);
	}
	if (time == 2) {
		//���ΰ �� �� �ƹ��ų� �Ծ �ȴ�.
		ret = eatPill(days+1, 0, 0, front) + eatPill(days+1, 0, 1, front);
	}
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	//�ٸ� ���� �Ծ��ٰ� ����
	cout << eatPill(0, 0, 0,1);
}