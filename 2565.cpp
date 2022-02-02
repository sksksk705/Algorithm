#include <bits/stdc++.h>

using namespace std;

int dp[501];
int line[501];
int checkline(int start)
{
	if (line[start] == 0) return -1;				//�������� ���� ������ ������ ����.
	int& ret = dp[start];
	if (ret != 0) return ret;
	ret = 1;
	for (int next = start +1; next < 501; ++next)	//��� ����� ���� ���� �� �ۿ� ����.
	{
		if (line[next] > line[start] || start == 0)
		{
			ret = max(ret, checkline(next) + 1);	//��� ���ο� ���� ���������� ����
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	line[0] = 501;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		line[a] = b;
	}
	int result = n - checkline(0) + 1;				//0���� �����θ� �����ϱ� ������ ����� 1�� ������
	cout << result;
}