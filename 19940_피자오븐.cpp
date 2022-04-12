//2022_04_12 ��������Ǯ��
//19940�� ���� ����

//N�� 1000���̶� DP�Ұ���, �׽�Ʈ ���̽� 100���� ����ȭ �ʿ�
//�׸���� Ǯ����� �Ǵµ� �޸���ƽ���� �غ����� ��ɺθ���...
#include <bits/stdc++.h>

using namespace std;

int button[5];
int answer[5];
int n;
int best;
int oven[5]{ 60,10,-10,1,-1 };

//�׸���� ����ġ��
int simpleheuristic(int remainTime) {
	if (remainTime < 0)
		return abs(remainTime / 11);
	else
		return remainTime / 60 + remainTime % 60 /11;
}

void solve(int buttonPush, int remainTime) {
	if (remainTime == 0) {
		if (buttonPush < best)
		{
			best = buttonPush;
			for (int j = 0; j < 5; ++j)
				answer[j] = button[j];
		}
		return;
	}

	if (buttonPush + simpleheuristic(remainTime) > best)
		return;

	if (remainTime < n - 60 || remainTime > n + 10)
		return;

	for (int i = 4; i >= 0; --i)
	{
		button[i]++;
		solve(buttonPush + 1, remainTime - oven[i]);
		button[i]--;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		//�׸���� ����ġ��
		best = n / 60 + n % 60 / 10 + n % 10;

		//�ʱ� ����
		answer[0] = n / 60;
		answer[1] = n % 60 / 10;
		answer[3] = n % 10;

		solve(0,n);
		for (int i = 0; i < 5; ++i) {
			cout << answer[i] << ' ';
		}
		cout << "\n";
		memset(button, 0, sizeof(button));
		memset(answer, 0, sizeof(answer));
	}
}