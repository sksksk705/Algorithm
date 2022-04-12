//2022_04_12 랜덤문제풀이
//19940번 피자 오븐

//N이 1000만이라 DP불가능, 테스트 케이스 100개라 최적화 필요
//그리디로 풀었어야 되는데 휴리스틱으로 해보려고 욕심부린듯...
#include <bits/stdc++.h>

using namespace std;

int button[5];
int answer[5];
int n;
int best;
int oven[5]{ 60,10,-10,1,-1 };

//그리디로 가지치기
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
		//그리디로 가지치기
		best = n / 60 + n % 60 / 10 + n % 10;

		//초기 설정
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