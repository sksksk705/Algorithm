//2022_05_15 ssafy준비
//15684번 사다리조작

//완전탐색으로 풀어보려고 했는데 로직이 이상함...
#include <bits/stdc++.h>

using namespace std;

int MAX = 987654321;
bool bridge[12][32];
int n, m, h;
void input() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		bridge[a][b] = true;
	}
}

vector<int> getLast() {
	vector<int> row;
	for (int i = 1; i <= n; ++i)
		row.push_back(i);
	
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (bridge[i][j])
				swap(row[j-1], row[j]);
		}
	}

	return row;
}

bool is_increasing(vector<int> vec)
{
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] < vec[i - 1])
			return false;
	}
	return true;
}

//한개씩 추가하면서 3개까지 가능하게 해보려 했는데 뭔가 로직이 이상함.
int ladderGame(int row, int col,int limit) {
	int ret = MAX;
	if (limit > 3 || row > h)
		return MAX;
	vector<int> result = getLast();
	if (is_increasing(result))
		return limit;

	int nextrow = row + (col / (n-1));
	int nextcol = col % (n - 1) + 1;

	if (bridge[row][col])
		ret = min(ret, ladderGame(nextrow, nextcol, limit));
	else {
		bridge[row][col] = true;
		ret = min(ret, ladderGame(nextrow, nextcol, limit + 1));
		bridge[row][col] = false;
	}

	return ret;
}

int main() {
	input();
	int result = ladderGame(0, 0, 0);
	cout << result;
}