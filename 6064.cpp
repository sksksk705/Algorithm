#include <iostream>
#define FASTIO		ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
	FASTIO;

	int T;
	cin >> T;
	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		if (y == N)
			y = 0;
		long long result = x;
		while (result % N != y)
		{
			result += M;
			if (result >= M * N) {
				result = -1;
				break;
			}
		}
		cout << result<<'\n';
	}
}