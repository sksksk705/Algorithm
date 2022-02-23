#include <iostream>
#define FASTIO		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;


int dist[100001];
int trees[100001];
int N;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int findProperDist()
{
	int distneed = 1000000001;
	for (int i = 2; i < N-1; ++i)
	{
		distneed = min(distneed, gcd(dist[i], dist[i + 1]));
	}
	return distneed;
}
int main()
{
	FASTIO;

	cin >> N;
	int maxdist = -1;
	for (int i = 1; i <= N; ++i)
	{
		cin >> trees[i];
		dist[i] = trees[i] - trees[i - 1];
	}

	int properDist = findProperDist();
	if (properDist == 1000000001)
		properDist = 1;
	int result = 0;
	for (int i = 2; i <= N; i++)
	{
		result += dist[i] / properDist-1;
	}
	cout << result;
}