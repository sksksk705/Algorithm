//2022_04_13 랜덤문제풀이
//2073 수도배관공사 18:56분 시작

//시간 2초, 메모리 128mb -> 그리디 x
//입력 10만, 350개 -> dp 불가능
//목표: 수도관의 최대용량 -> 최적화
//일단 완전탐색을 구현해보고자 함.

//19:48분 정답
#include <bits/stdc++.h>

using namespace std;

int dist, pipe; //거리, 파이프 수
int lengthSum[351];
int best = 0;
vector<pair<int, int>> pipes;

//가지치기용 함수
bool simpleHeuristic(int remain, int idx)
{
	//남은 파이프를 전부 써도 거리가 안 되는 경우.
	return remain - lengthSum[idx] > 0;
}

//완전탐색 구현완료, 경우의 수 2의 350승 - 최적화 필요
//가지치기 구현완료
//idx: 현재 파이프
//remain: 남은 거리
//currentCap: 현재 용량
void solve(int idx, int remain, int currentCap)
{
	//가지치기
	if (currentCap <= best || simpleHeuristic(remain, idx))
		return;

	//기저사례1:파이프의 길이가 길거나 모든 파이프를 탐색한 경우
	if (idx > pipe || remain < 0)
		return;

	//기저사례2: 정확한 길이의 파이프를 만든 경우
	if (remain == 0) {
		best = max(currentCap, best);
		return;
	}

	//해당 파이프를 사용하거나 사용하지 않거나
	solve(idx + 1, remain - pipes[idx].first, min(currentCap, pipes[idx].second));
	solve(idx + 1, remain, currentCap);
}


int main() {
	cin >> dist >> pipe;
	for (int i = 0; i < pipe; ++i)
	{
		int length, capacity;
		cin >> length >> capacity;
		pipes.push_back(make_pair(length, capacity));
	}
	sort(pipes.begin(), pipes.end());

	//i부터 끝까지 파이프길이의 합
	lengthSum[pipe - 1] = pipes[pipe - 1].first;
	for (int i = pipe - 2; i >= 0; --i)
		lengthSum[i] = lengthSum[i + 1] + pipes[pipe - 1].first;

	solve(0, dist, INT_MAX);
	cout << best;
}