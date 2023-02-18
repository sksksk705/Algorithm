//2022_05_07 ��������Ǯ��
//23310 ��ſ� ����������

//ù��° ���� ���� ���ƿ��� ����Ŭ�� ���ϰ� �ش� ����Ŭ�� ������ ���� ���� �� �߿� �� �տ� ��.

#include <bits/stdc++.h>

using namespace std;

int GDC(int a, int b)
{
	if (a % b == 0)
		return b;
	return GDC(b, a % b);
}

int LCM(int a, int b)
{
	return a * b / GDC(a, b);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> task;
	vector<int> days(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> task[i];
	}


	int cycleDay = LCM(n, m);
	int rotation = cycleDay / n;


	for (int i = 0; i < n; ++i)
	{
		days[i] += task[i] / rotation * cycleDay;
		task[i] %= rotation;
	}


	return 0;
	
}