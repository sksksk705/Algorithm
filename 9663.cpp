#include <bits/stdc++.h>

using namespace std;

int board[15];
int cnt;
int n;
bool canPut(int cdx)
{
	for (int i = 0; i < cdx; ++i)
	{
		if (board[i] == board[cdx] || abs(i - cdx) == abs(board[i] - board[cdx]))
			return false;
	}
	return true;
}

void nqueen(int cdx) {
	if (cdx == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		board[cdx] = i;
		if (canPut(cdx)) {
			nqueen(cdx + 1);
		}
	}
}

int main()
{
	cin >> n;
	nqueen(0);
	cout << cnt;
}