//2022_05_03 랜덤문제풀이
//9007번 카누선수

//완탐:O(n^4)
//k가 40000000이기 때문에 dp를 쓰려면 줄여야 함
//이분 탐색을 4번 활용해보자

//구현은 했는데 결과값으로 큰 값이 나오면 그보다 작은 값을 서칭하지 않는 문제점이 발생 
//정렬을 반대로 하면 그보다 큰 값을 더 이상 찾아보지 못한다. 즉 1반의 1번을 골랐을 때의 가장 이상적인 답이 목표값보다 크다면 더 이상 서칭하지 않는다...
//2개일때 hi가 0에서 -1가서 2개일 때는 위로도 서칭해보게 했지만 안 된다... 분할 정복을 써야하나...?
//검색해보니 그냥 위 2개 아래 2개씩 다 더한 배열을 만들어서 했다.
#include <bits/stdc++.h>

using namespace std;

void input(vector<vector<int>>& students, int n) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			int weight;
			cin >> weight;
			students[i].push_back(weight);
		}
	}

	for (int i = 0; i < 4; ++i)
		sort(students[i].begin(), students[i].end());
}


int KanuPlayer(vector<vector<int>> students, int classroom, int totalWeight, int stuNum) {
	if (classroom > 3)
		return 0;
	int hi = stuNum-1;
	int lo = 0;
	int bestdiff = 987654321;
	int bestWeight = 987654321;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int stuWeight = students[classroom][mid];
		int teamWeight = stuWeight + KanuPlayer(students, classroom + 1, totalWeight - stuWeight, stuNum);
		if (teamWeight< totalWeight || stuNum == 2) {
			lo = mid+1;
		}
		else
			hi = mid-1;

		int nowdiff = abs(totalWeight - teamWeight);
		if (nowdiff <= bestdiff) {
			if (nowdiff < bestdiff)
				bestWeight = teamWeight;
			else
				bestWeight = min(bestWeight, teamWeight);
			bestdiff = nowdiff;
		}
	}
	return bestWeight;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int k, n;
		cin >> k >> n;
		vector<vector<int>> students(4);
		input(students,n);
		int result = KanuPlayer(students, 0, k, n);
		cout << result<<'\n';
	}

}