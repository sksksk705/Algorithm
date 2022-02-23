#include <iostream>
#include <cmath>
#include <vector>
#define FASTIO		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
long long a, b;
bool isPrime[2000001];
vector<int> prime;
const int MAX = 2000000;

void makePrime()
{
	for (long long i = 2; i <= MAX; ++i)
		isPrime[i] = true;
	for (long long i = 2; i <= MAX; ++i)
	{
		if (isPrime[i]) {
			prime.push_back(i);
			for (long long j = i*i; j <= MAX; j+=i)
				isPrime[j] = false;
		}
	}
}

bool isCouple()
{
	long long comb = a + b;
	if (comb % 2 == 0) {
		if (comb == 2)
			return false;
		return true;
	}
	else {
		long long possible = comb - 2;
		if (possible <= MAX)
			return isPrime[possible];
		for (int i = 0; i < prime.size(); ++i)
		{
			if (possible % prime[i] == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	FASTIO;
	makePrime();
	int T;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		if (isCouple())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}