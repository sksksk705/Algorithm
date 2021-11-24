#include <bits/stdc++.h>

using namespace std;

int dp[3][301]; //������ ���̺�
int stairs[301]; //��� ���� ���̺�
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int score;
		cin >> score;
		stairs[i] = score;
	}
	dp[1][1] = stairs[1];
	for (int i = 2; i <= n; ++i) {
		dp[1][i] = max(dp[2][i - 2],dp[1][i-2]) + stairs[i]; //ó�� ��� �� 2�ܰ��� 1�� ���� ���̰ų� 2�� ���� ���� ������ ���� ��� ������ ��.
		dp[2][i] = dp[1][i - 1] + stairs[i]; //2��° ��� �� ���� ����� ������ ���� ����� ������ �߰�.
	}

	cout << max(dp[1][n], dp[2][n]); //������ ��ƾ��ϱ� ������ ���� �ܰ��� ����.
}