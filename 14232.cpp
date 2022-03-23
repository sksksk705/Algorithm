//2022_03_23 랜덤 문제 풀이
//14232 보석 도둑 

//20:40 시작 아마도 약수들을 찾는 문제인 것 같다.
//n의 제곱근만큼 모든 소수를 찾아놔야겠다. 
//20:56 정답
#include <bits/stdc++.h>
bool notprime[10000001];
using namespace std;

int main() {
	long long k;
	cin >> k;
	vector<int> prime;

	for (int i = 2; i < sqrt(k); ++i) {
		if (!notprime[i]) {
			prime.push_back(i);
			for (int j = i + i; j < sqrt(k); j += i) {
				notprime[j] = true;
			}
		} 
	}
	vector<long long> result;
	int idx = 0;
	while (idx < prime.size())
	{
		if (k % prime[idx] == 0)
		{
			result.push_back(prime[idx]);
			k /= prime[idx];
			idx = 0;
			continue;
		}
		idx++;
	}
	if (k != 1)
		result.push_back(k);
	cout << result.size() << '\n';
	for (auto gem : result)
		cout << gem << ' ';
}