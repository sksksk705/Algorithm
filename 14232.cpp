//2022_03_23 ���� ���� Ǯ��
//14232 ���� ���� 

//20:40 ���� �Ƹ��� ������� ã�� ������ �� ����.
//n�� �����ٸ�ŭ ��� �Ҽ��� ã�Ƴ��߰ڴ�. 
//20:56 ����
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