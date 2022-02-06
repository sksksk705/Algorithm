#include <bits/stdc++.h>

using namespace std;

int m;
int n;
vector<int> trees;
int get_max_height(int trees_in_same_height, int goal, int max_height)
{
	max_height -= goal / trees_in_same_height;
	goal %= trees_in_same_height;
	while (goal > 0)
	{
		goal -= trees_in_same_height;
		max_height--;
	}
	return max_height;
}
int get_tree(int goal){
	int max_height = trees[0];
	int idx = 0;
	int trees_in_same_height = 1;
	while (true)
	{
		if (trees_in_same_height == n) {
			return get_max_height(trees_in_same_height, goal, max_height);
		}
		int next_height = trees[idx] - trees[idx + 1];
		if (next_height * trees_in_same_height < goal) {
			goal -= next_height * trees_in_same_height;
			trees_in_same_height++;
			idx++;
			max_height -= next_height;
			continue;
		}
		return get_max_height(trees_in_same_height, goal, max_height);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int height;
		cin >> height;
		trees.push_back(height);
	}
	sort(trees.begin(), trees.end(),greater<int>());
	int result = get_tree(m);
	cout << result;
}