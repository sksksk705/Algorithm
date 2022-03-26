//2022_03_26 동적계획법
//2281 데스노트: 최적화문제 19:49

//실수1: 정해진 순서인데 마음대로 해버림
//20:47분 정답
#include <bits/stdc++.h>

using namespace std;

int cache[1000][1001];
int name[1000];
const int INF = 987654321;

int n, m;

int deathNote(int idx, int sum)
{
	//기저사례1: 모든 이름을 다 썼다면 0을 반환
	if (idx >= n)
		return 0;

	//기저사례2: 이 줄의 끝까지 다 썼다면 다음 줄에 쓴다.
	if (sum > m)
		return deathNote(idx+1, name[idx] + 1);

	int& ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = INF;
	if (name[idx] <=  m - sum)
	{
		ret = min(ret, deathNote(idx + 1, sum + name[idx] + 1));
	}
	ret = min(ret, deathNote(idx + 1, name[idx] + 1) + (int)pow(m - sum + 1, 2));
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> name[i];
	}
	memset(cache, -1, sizeof(cache));

	cout << deathNote(0,0);
	return 0;
}