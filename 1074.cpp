#include <bits/stdc++.h>

using namespace std;

int r;
int c;
int Z(int x, int y,int size) //rÀÌ y, c°¡ x  map[y][x]
{
	int ret = 0;
	if (y == r && x == c)
		return 0;
	if ((r >= y && r < y + size) &&
		(c >= x && c < x + size))
	{
		int half = size / 2;
		ret += (r - y >= half) * 2 * (half * half) + (c - x>= half) * (half * half);
		ret += Z(x, y, half);
		ret += Z(x + half, y, half);
		ret += Z(x, y + half, half);
		ret += Z(x + half, y + half, half);
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	cin >> r >> c;
	cout<<Z(0, 0, pow(2, n));
}