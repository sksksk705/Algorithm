#include <bits/stdc++.h>

using namespace std;
int n;
int vec[100001];
long long solution(int sum, int idx,int seq) {
	long long ret = 0;
	if (seq == 4)
		return 1; 
	long long miniSum = 0;
	while (idx < n - 3 + seq)
	{
		miniSum += vec[idx];
		if (miniSum == sum)
			ret += solution(sum, idx+1, seq+1);
		idx++;
	}
	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> vec[i];
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n - 3; ++i) {
		sum += vec[i];
		ans += solution(sum, i+1, 1);
	}
	cout << ans;
}