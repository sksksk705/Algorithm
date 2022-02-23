#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long w, h, n, m;

	cin >> h >> w >> n >> m;
	long long rowpeople = h / (n+1);
	if (h - (n + 1)*rowpeople > 0) rowpeople++;

	long long colpeople = w / (m + 1);
	if (w - (m + 1)*colpeople > 0) colpeople++;

	cout << rowpeople * colpeople;
}