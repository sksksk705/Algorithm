//2022_04_18 ��������Ǯ��
//16434�� �巡�� �� ����

//�ð� 1��, �޸� 256mb ��Ʈ�� ����
//��ǥ �ּ� H -> ����ȭ
//��������� ���� ����� int ������ ������ �Ѵ� �� ����.
//���� 2�� ���� ���� 12������ ������ ������ ���� �� �Ǵµ�...?
//long long���� ��� ������ Ŀ������
#include <bits/stdc++.h>

using namespace std;

int n;
int dungeon[123456][3];
const long long INF = LLONG_MAX;
long long hpMax , hAtk;


long long clearDungeon()
{
	//ans: �������� ȸ�������� ������ �� �� ���� ü�°��� �����ؾ���.
	long long ans = 0;
	for (int room = 0; room < n; ++room)
	{
		long long atk = dungeon[room][1];
		long long hp = dungeon[room][2];
		if (dungeon[room][0] == 2) {
			hpMax = hpMax - hp > 1 ? hpMax - hp : 1;
			hAtk += atk;
		}
		else
			//���� �޾ƾ��ϴ� �������� �ִ�ü�¿� ����.
			hpMax += ((hp + hAtk - 1) / hAtk -1) * atk;
		ans = max(ans, hpMax);
	}
	return ans;
}

void input() {
	cin >> n >> hAtk;
	for (int i = 0; i < n; ++i)
	{
		cin >> dungeon[i][0] >> dungeon[i][1] >> dungeon[i][2];
	}
	hpMax = 1;
}


int main() {
	input();
	cout << clearDungeon();
}
