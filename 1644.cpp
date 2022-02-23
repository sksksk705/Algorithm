#include <iostream>
#include <vector>
using namespace std;

bool isprime[4000001];
vector<int> prime;
int n;

void makePrime()
{
	for (int i = 2; i <= n; ++i)
	{
		if (!isprime[i]) {
			prime.push_back(i);
			for (int j = 1; j * i <= n; ++j)
			{
				isprime[j*i] = true;
			}
		}
	}
}

int seqplus(int now, int idx)
{
	int ret = 0;
	if (idx > prime.size())
		return 0;
	if (now == n) {
		return 1;
	}
	if (now + prime[idx + 1] > n)
		return 0;
	ret = seqplus(now + prime[idx + 1], idx + 1);
	return ret;
}

int main()
{
	cin >> n;
	makePrime();
	int result = 0;
	for (int i = 0; i < prime.size(); ++i)
	{
		result += seqplus(prime[i],i);
	}
	cout << result;
}