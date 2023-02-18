//2022_05_15 ssafy�غ�
//15684�� ��ٸ�����

//����Ž������ Ǯ����� �ߴµ� ������ �̻���...
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

//�Ѱ��� �߰��ϸ鼭 3������ �����ϰ� �غ��� �ߴµ� ���� ������ �̻���.
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