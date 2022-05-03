//2022_05_03 랜덤문제풀이
//12764번 싸지방에 간 준하

#include <bits/stdc++.h>

using namespace std;

int pc[100001];
bool Using[100001];

int main() {
	int n;
	cin>>n;
	int pcNeed = 1;
	vector<pair<int, int>> people;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> useQ;
	for (int i = 0; i < n; ++i) {
		int p, q;
		cin >> p >> q;
		people.push_back(make_pair(p, q));
	}

	//시작 시간 순서대로 정렬
	sort(people.begin(), people.end());

	for (int person = 0; person < n; ++person) {
		int start, end;
		start = people[person].first;
		end = people[person].second;

		//현재 사람의 시작시간으로 기준으로 그 전에 다 쓴 사람을 모두 내보내고 해당 컴퓨터를 사용가능하게 변경
		while (!useQ.empty() && useQ.top().first < start) {
			Using[useQ.top().second] = false;
			useQ.pop();
		}

		//아무도 컴퓨터를 하고 있지 않다면 첫번째 자리에 배정
		if (useQ.empty()) {
			useQ.push(make_pair(end, 0));
			pc[0]++;
			Using[0] = true;
		}
		else{
			//모든 pc가 이용중이라면 pc를 하나 더 구매해서 배정
			if (useQ.size() == pcNeed) {
				useQ.push(make_pair(end, pcNeed));
				Using[pcNeed] = true;
				pc[pcNeed]++;
				pcNeed++;
			}
			else {
				//비어있는 pc자리 중 가장 앞에 있는 자리에 배정
				for (int i = 0; i < pcNeed; ++i)
				{
					if (!Using[i]) {
						useQ.push(make_pair(end, i));
						Using[i] = true;
						pc[i]++;
						break;
					}
				}
			}
		}
	}
	
	cout << pcNeed<<'\n';
	for (int i = 0; i < pcNeed; ++i)
		cout << pc[i] << " ";
}
