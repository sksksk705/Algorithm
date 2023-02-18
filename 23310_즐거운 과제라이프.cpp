//2022_05_07 랜덤문제풀이
//23310 즐거운 과제라이프

//첫번째 쉬는 날로 돌아오는 사이클을 구하고 해당 사이클로 나눠서 가장 작은 것 중에 맨 앞에 것.

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