#include <bits/stdc++.h>

using namespace std;

int n;

int leftarm;
int rightarm;
int leftleg;
int rightleg;

bool head;

pair<int, int> heart;
pair<int, int> waist;

int cookie[1001][1001];
int dx[4]{ 0,0,-1,1 };
int dy[4]{ 1,-1,0,0 };
pair<int,int> getend(int x, int y, int dir) {
	while (true) {
		int nextx = x + dx[dir];
		int nexty = y + dy[dir];
		if (cookie[nexty][nextx] != 1 ||
			nextx < 0 || nextx > n ||
			nexty < 0 || nexty > n)
			return make_pair(x, y);
		x = nextx;
		y = nexty;
	}
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < n;++j){
			if (s[j] == '*') {
				if (!head) {
					heart = { i + 1,j+1};
					head = true;
				}
				cookie[i][j+1] = 1;
			}
		}
	}

	int heartx = heart.second;
	int hearty = heart.first;

	leftarm = heartx - getend(heartx, hearty, 2).first;
	rightarm = getend(heartx, hearty, 3).first - heartx;
	waist = getend(heartx, hearty, 0);

	int waistx = waist.first;
	int waisty = waist.second;

	leftleg =  getend(waistx - 1, waisty + 1, 0).second - waisty;
	rightleg = getend(waistx + 1, waisty + 1, 0).second - waisty;

	cout << hearty << " " << heartx<<'\n';
	cout << leftarm << " " << rightarm << " " << waisty - hearty
		<< " " << leftleg << " " << rightleg;
}