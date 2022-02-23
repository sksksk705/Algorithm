#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct my_func {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;      //작은 거부터 나오게 하려면 > 큰거는 <
		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, my_func> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top()<<'\n';
			pq.pop();
			continue;
		}
		pq.push(x);
	}
}