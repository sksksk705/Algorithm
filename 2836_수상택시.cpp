//2022_04_28 랜덤문제풀이
//2836번 수상택시

//타는 곳이 내리는 곳보다 앞에 있는 건 고려하지 않아도 된다. 가는 동안 알아서 됨
//내리는 곳이 타는 곳보다 작을 때: 겹치는 구간이 있다면 태우는 게 무조건 이득.

//m이 최대 10억이기 때문에 거리는 최대 30억이 나올 수 있음(int 범위 초과)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; ++i)
	{
		int depart, land;
		cin >> depart >> land;
		//내리는 곳이 타는 곳보다 뒤에 있다면 고려하지 않는다.
		if (land >= depart)
			continue;

		//내리는 곳을 기준으로 오름차순 정렬
		pq.push(pair<int, int>(land, depart));
	}

	//prev: 이전 위치
	//pos: 현재 위치
	//dist: 이동한 거리
	int prev = 0;
	int pos = 0;
	long long dist = 0;
	while (!pq.empty()) {
		pos = pq.top().second;
		dist += pos - prev;
		int toward = pq.top().first;
		pq.pop();
		//구간이 겹치는 사람이 있다면 차에 태운다.
		while (!pq.empty()&&pq.top().first < pos)
		{
			auto nextPerson = pq.top();
			pq.pop();
			//현재위치가 다음 타는 위치보다 크면 고려하지 않는다.
			if (pos > nextPerson.second)
				continue;

			//전에 태운 위치에서 다음 타는 위치까지 이동
			prev = pos;
			pos = nextPerson.second;
			dist += pos - prev;
		}
		//구간이 겹치는 사람을 다 태우고 첫번째 사람의 내리는 장소로 간다.
		dist += pos - toward;

		//더 이상 들릴 곳이 없다면 내린 곳에서 끝으로 간다.
		if (pq.empty())
			dist += m - toward;

		prev = toward;
	}

	cout << dist;
}