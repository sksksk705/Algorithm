//2022_03_29 랜덤문제풀이
//14658 하늘에서 별똥별이 빗발친다.

//18:40분 시작 19:17분 저녁
//19:47분 시작 20:02분 휴식
//아이디어: 별똥별 1개를 기준으로 최대 몇개의 별똥별을 받아 낼 수 있는지 계산 
//완탐으로 만드니까 시간이 너무 오래걸림 - 왼쪽 위의 기준을 해당 별의 idx로 바꿈(dp가 가능해짐)
//왼쪽 위를 idx로 했을 때 이때까지 right_bottom을 저장할 수가 없음(추가하면 dp불가능)
//20:43포기

#include <bits/stdc++.h>

using namespace std;

int N, M, L, K;
const int INF = 987654321;
pair<int,int> star[100];
int cache[101][101][101];
int solution(int idx, int left_star, int top_star) {
	int& ret = cache[idx+1][left_star+1][top_star+1];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = idx + 1; i < K; ++i) {
		if (idx == -1) {
			ret = max(ret, solution(i, i, i) + 1);
			continue;
		}
		if (star[i].first - star[left_star].first >= L ||
			star[i].second - star[top_star].second >= L)
			continue;
		int next_left = star[left_star].first > star[i].first ? i : left_star;
		int next_top = star[top_star].second > star[i].second ? i : top_star;
		ret = max(ret, solution(i, next_left, next_top)+1);
	}
	return ret;
}

using namespace std;

int main() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		star[i] = make_pair(x, y);
	}
	memset(cache, -1, sizeof(cache));
	cout << K - solution(-1, -1, -1);
}