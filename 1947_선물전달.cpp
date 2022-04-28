//2022_04_28 랜덤문제풀이
//1947_선물전달

//무조건 1번부터 선물을 주기 시작한다고 가정했을 때, 2명이 남으면 1가지 방법밖에 없다.
//스택 오버플로우 나니까 바텀업으로 해보자
#include <bits/stdc++.h>

using namespace std;

int cache[1000001];
const int MOD = 1000000000;

//스택 오버플로우
long long solve(long long N)
{
	int& ret = cache[N];
	if (ret != -1) return ret;
	ret = (N - 1) * solve(N - 1) % MOD;
	ret += (N - 1) * solve(N - 2) % MOD;
	ret %= MOD;
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cache[2] = 1;
	cache[1] = 0;
	long long n;
	cin >> n;

 	for (int i = 3; i <= 1000000; ++i) {
		cache[i] = (i - 1) * cache[i - 1] % MOD;
		cache[i] += (i - 1) * cache[i - 2] % MOD;
		cache[i] %= MOD;
	}
	cout <<cache[n];
}