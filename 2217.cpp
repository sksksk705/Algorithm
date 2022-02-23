#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> rope;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N;++i)
	{
		int r;
		cin >> r;
		rope.push_back(r);
	}
	sort(rope.begin(), rope.end());
	long long maxWeight = -1;
	for (int i = 0; i < N; ++i)
	{
		maxWeight = max(maxWeight, rope[i] * (N - i));
	}
	cout << maxWeight;
}