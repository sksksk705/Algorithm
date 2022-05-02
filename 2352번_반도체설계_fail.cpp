//2022_05_02 랜덤문제풀이
//2352번 반도체설계

//증가 수열의 최대 길이 구하기 n = 40000;
//탑다운이 안 되니까 머리가 하얘졌다 다음에 다시 하는 걸로
#include <bits/stdc++.h>

using namespace std;

int cache[40002];
int connect[40001];
int n;

//stackoverflow가 생긴다. 반복문으로 가능한가?
int topDown(int idx) {
	int& ret = cache[idx+1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = idx + 1; i < n; ++i) {
		if (idx == -1 || connect[idx] < connect[i])
			ret = max(ret, topDown(i) + 1);
	}
	return ret;
}

int bottomUp() {
	int ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		cache[i] = 1;
		for (int j = i+1; j < n; ++j) {
			if (connect[i] < connect[j])
			{
				cache[i] = max(cache[i + 1], cache[j] + 1);
				break;
			}
		}
		cache[i] = max(cache[i], cache[i + 1]);
		ret = max(ret, cache[i]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> connect[i];

	int result = bottomUp();
	cout << result;
}