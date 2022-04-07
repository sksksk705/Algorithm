//2022_04_07 그리디
//19621 회의실 배정2

//가장 먼저 끝나는 회의를 정하고 해당 회의와 겹치는 회의들을 취소한다.
//최대 인원수, n이 25이기 때문에 dp를 사용해야할듯
//dp를 사용하기에는 시간이 intMAX이기 때문에 완탐으로 해결
//16:34 시간을 기준으로 하는 게 아니라 삼각형 최대경로처럼 해야할듯
#include <bits/stdc++.h>

using namespace std;

int cache[25];
int people[25];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		cin >> people[i];
	}
	int ret = 0;
	ret = max(people[0], people[1]);
	cache[0] = people[0];
	cache[1] = people[1];
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < i-1; ++j) {
			cache[i] = max(cache[i],cache[j] + people[i]);
		}
		ret = max(ret, cache[i]);
	}
	cout << ret;
}