//2022_04_28 ��������Ǯ��
//1947_��������

//������ 1������ ������ �ֱ� �����Ѵٰ� �������� ��, 2���� ������ 1���� ����ۿ� ����.
//���� �����÷ο� ���ϱ� ���Ҿ����� �غ���
#include <bits/stdc++.h>

using namespace std;

int cache[1000001];
const int MOD = 1000000000;

//���� �����÷ο�
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