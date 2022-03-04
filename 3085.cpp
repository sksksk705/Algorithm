#include <bits/stdc++.h>

using namespace std;

char board[51][51];
int n;
bool visited[51][51];
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int checkMaxCandy() {
	int MAX = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-1;) {
			int length = 1;
			while (j < n-1 && board[i][j] == board[i][j + 1]) {
				length++;
				j++;
			}
			MAX = max(MAX, length);
			j++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-1;) {
			int length = 1;
			while (j < n-1 && board[j][i] == board[j+1][i]) {
				length++;
				j++;
			}
			MAX = max(MAX, length);
			j++;
		}
	}
	return MAX;
}

void swap(int x1, int y1, int x2, int y2) {
	char temp;
	temp = board[y1][x1];
	board[y1][x1] = board[y2][x2];
	board[y2][x2] = temp;
}

int bruteforce(int x, int y) {
	int MAX = -1;
	if (visited[y][x])
		return 0;
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (nextx < 0 || nextx >= n ||
			nexty < 0 || nexty >= n ||
			visited[nexty][nextx]||
			board[nexty][nextx] == board[y][x])
			continue;
		swap(x, y, nextx, nexty);
		MAX = max(MAX,checkMaxCandy());
		swap(x, y, nextx, nexty);
	}
	return MAX;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	
	int result = checkMaxCandy();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			result = max(result,bruteforce(j, i));
	cout << result;
}