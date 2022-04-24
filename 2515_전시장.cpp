//2022_04_24 랜덤문제풀이
//2515 전시장

//dp문제라고 일단 생각 차이가 s이상인 증가수열의 가격의 최대합을 반환하면 되기 때문
//모든 그림을 다 산다 했을 때 최대 값 3억 int 범위로 가능
//탑다운 dp는 시간초과가 난다. 바텀업이나 그리디를 생각해봐야할듯.
//바텀업 성공
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000001;
int cache[300001];
int dp[MAX];
bool visited[MAX];
int n,s;


//탑다운 dp 시간초과
int setPainting(int start, vector<pair<int, int>>& painting)
{
	int& ret = cache[start +1];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++next)
	{
		int nextHeight = painting[next].first;
		int nextPrice = painting[next].second;
		if (start == -1 || nextHeight - painting[start].first >= s)
		{
			ret = max(ret, setPainting(next, painting) + nextPrice);
		}
	}
	return ret;
}

//그리디: 가장 비싼 것 위 아래의 범위에는 그림이 없어야함.
//틀렸습니다.
int greedy(vector<pair<int,int>> painting)
{
	int ret = 0;
	for (auto paint : painting)
	{
		if (visited[paint.second])
			continue;
		ret += paint.first;
		for (int i = paint.second - s+1; i < paint.second + s; ++i)
		{
			if (i < 0 || i >= MAX)
				continue;
			visited[i] = true;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	vector<pair<int,int>> painting(n);

	//탑다운 dp
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; ++i)
	{
		//탑다운
		//cin >> painting[i].first >> painting[i].second;

		//바텀업
		int height, price;
		cin >> height >> price;
		dp[height] = max(dp[height], price);
	}

	//그리디
	/*for (int i = 0; i < n; ++i)
	{
		cin >> painting[i].second >> painting[i].first;
	}*/

	//탑다운
	sort(painting.begin(), painting.end(),greater<pair<int,int>>());

	//int result = setPainting(-1, painting);
	//int result = greedy(painting);

	//바텀업
	for (int i = s; i < MAX; ++i)
	{
		dp[i] = max(dp[i-1], dp[i - s] + dp[i]);
	}
	cout << dp[MAX-1];
}