//2022_04_14 계산기하
//11758번 CCW

//3개의 외적?
#include <bits/stdc++.h>

using namespace std;

//c를 기준으로 a가 어디에 있는가?
double ccw(pair<int, int> a, pair<int, int> c)
{
	return -(a.first * c.second - a.second * c.first);
}

double ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	return ccw(make_pair(a.first - b.first, a.second - b.second), 
				make_pair(c.first - b.first, c.second - b.second));
}



int main() {
	pair<int, int> a;
	pair<int, int> b;
	pair<int, int> c;

	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	double result = ccw(a, b, c);
	if (result > 0)
		cout << 1;
	else if (result < 0)
		cout << -1;
	else
		cout << 0;
	return 0;
}