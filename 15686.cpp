#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int INF = 987654321;


vector<pair<int, int>> house_vec, chicken_vec, test_vec;
bool visited[14];
int n, m;

int getChickenDis(int remain, int now_chicken)
{
	int ret = INF;
	if (remain == m)
	{
		int result = 0;
		for (auto house : house_vec)
		{
			int mini = INF;
			for (auto chicken : test_vec)
			{
				mini = min(mini, abs(house.first - chicken.first) + abs(house.second - chicken.second));
			}
			result += mini;
		}
		return result;
	}
	for (int i = now_chicken; i < chicken_vec.size(); ++i)
	{
		if (!visited[i])
		{
			test_vec.push_back(chicken_vec[i]);
			visited[i] = true;
			ret = min(ret, getChickenDis(remain + 1,i));
			test_vec.pop_back();
			visited[i] = false;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			int info;
			cin >> info;
			if (info == 1)
				house_vec.push_back(make_pair(col, row));
			if (info == 2)
				chicken_vec.push_back(make_pair(col, row));
		}
	}
	int result = getChickenDis(0,0);
	cout << result;

}