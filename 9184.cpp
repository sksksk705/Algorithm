#include <bits/stdc++.h>

using namespace std;


int dp[21][21][21];

int w(int a, int b, int c)
{
	if (a > 20 || b > 20 || c > 20) {
		a = b = c = 20;
	}
	int& ret = dp[a][b][c];
	if (ret != 0) return ret;
	if (a <= 0 || b <= 0 || c <= 0) {
		ret = 1;
		return ret;
	}
	if (a < b && b < c)
		ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return ret;
}
int main()
{
	int a = 0, b = 0, c = 0;
	fstream finout("9184.txt");
	finout >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1) {
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << '\n';
		}
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)<<'\n';
		finout >> a >> b >> c;
	}
}