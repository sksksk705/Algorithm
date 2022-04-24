//2022_04_24 ��������Ǯ��
//2515 ������

//dp������� �ϴ� ���� ���̰� s�̻��� ���������� ������ �ִ����� ��ȯ�ϸ� �Ǳ� ����
//��� �׸��� �� ��� ���� �� �ִ� �� 3�� int ������ ����
//ž�ٿ� dp�� �ð��ʰ��� ����. ���Ҿ��̳� �׸��� �����غ����ҵ�.
//���Ҿ� ����
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000001;
int cache[300001];
int dp[MAX];
bool visited[MAX];
int n,s;


//ž�ٿ� dp �ð��ʰ�
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

//�׸���: ���� ��� �� �� �Ʒ��� �������� �׸��� �������.
//Ʋ�Ƚ��ϴ�.
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

	//ž�ٿ� dp
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; ++i)
	{
		//ž�ٿ�
		//cin >> painting[i].first >> painting[i].second;

		//���Ҿ�
		int height, price;
		cin >> height >> price;
		dp[height] = max(dp[height], price);
	}

	//�׸���
	/*for (int i = 0; i < n; ++i)
	{
		cin >> painting[i].second >> painting[i].first;
	}*/

	//ž�ٿ�
	sort(painting.begin(), painting.end(),greater<pair<int,int>>());

	//int result = setPainting(-1, painting);
	//int result = greedy(painting);

	//���Ҿ�
	for (int i = s; i < MAX; ++i)
	{
		dp[i] = max(dp[i-1], dp[i - s] + dp[i]);
	}
	cout << dp[MAX-1];
}