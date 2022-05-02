//2022_04_30 랜덤문제풀이
//1301번 비즈공예

//사례의 수가 상당히 적어서 완전탐색 문제인 것 같음
//완전탐색으로 다가가보니 시간초과가 생긴다 - 휴리스틱으로 감소시켜볼까?
#include <bits/stdc++.h>

using namespace std;

//한 색상이 전체 갯수의 1/3 이상이면 만들 수 없다.
bool simpleHeuristic(const vector<int>& bizs) {
	double total = 0;
	for (auto amount : bizs) {
		total += amount;
	}
	int possible = ceil(total / 3);
	for (auto amount : bizs) {
		if (amount > possible)
			return false;
	}
	return true;
}

//완전탐색 - 시간초과 - 휴리스틱 추가 - 그럼에도 시간초과
int bizArt(int spices, int pprev, int prev, vector<int>& bizs) {
	int ret = 0;
	//휴리스틱 추가
	if (!simpleHeuristic(bizs))
		return ret = 0;
	bool usedAll = true;
	for (int color = 0; color < spices; ++color) {
		if (bizs[color] > 0)
			usedAll = false;
		if (bizs[color] > 0 && color != pprev && color != prev)
		{
			bizs[color]--;
			ret += bizArt(spices, prev, color, bizs);
			bizs[color]++;
		}
	}
	if (usedAll)
		return 1;
	return ret;
}


int main() {
	int n;
	cin >> n;
	vector<int> bizs(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> bizs[i];
	}
	int result = bizArt(n, -1, -1, bizs);
	cout << result;
}