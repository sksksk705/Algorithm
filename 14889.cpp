#include <bits/stdc++.h>

using namespace std;

int ability[21][21];
int diff = 987654321;
vector<int> start;
vector<int> link;
bool haveteam[21];
int n;

int start_score()
{
	int score = 0;
	for (int i = 0; i < start.size()-1; ++i)
	{
		for (int j = i + 1; j < start.size(); ++j)
		{
			score += ability[start[i]][start[j]];
			score += ability[start[j]][start[i]];
		}
	}

	return score;
}
int link_score()
{
	int score = 0;
	for (int i = 0; i < link.size() - 1; ++i)
	{
		for (int j = i + 1; j < link.size(); ++j)
		{
			score += ability[link[i]][link[j]];
			score += ability[link[j]][link[i]];
		}
	}
	return score;
}

void startnLink(int player, int startmember)
{
	if (startmember == n/2) {
		for (int i = 1; i <= n; ++i)
		{
			if (!haveteam[i])
				link.push_back(i);
		}
		int my_diff = abs(start_score() - link_score());
		if (my_diff < diff)
			diff = my_diff;
		link.clear();
		return;
	}
	for (int i = player+1; i < n; ++i)
	{
		if (!haveteam[i] || player == 0)
		{
			haveteam[i] = true;
			start.push_back(i);
			startnLink(i,startmember+1);
			start.pop_back();
			haveteam[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> ability[i][j];
		}
	}
	startnLink(0,0);
	cout << diff;
}