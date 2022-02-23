#include <iostream>
#include <cstring>

#define FASTIO			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

bool visited[100001];
bool done[100001];
int graph[100001];
int cnt;
void checkcicle(int now)
{
	visited[now] = true; 
	int next = graph[now];
	if (!visited[next])
		checkcicle(next);
	else if (!done[next])
	{
		for (int i = next; i != now; i = graph[i])
			cnt++;
		cnt++;
	}
	done[now] = true;
}

int main()
{
	FASTIO;
	int T;
	cin >> T;
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> graph[i];
		cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (!visited[i])
				checkcicle(i);
		cout << n - cnt <<'\n';
	}
	return 0;
}