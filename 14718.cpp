//2022_03_23 랜덤문제풀기
//14718 용감한 용사 진수

//17:12시작 딱 봤을 때는 어떤 유형인지 몰랐음, 완탐부터 생각
//17:42 따로 높을 때 이기는 게 아니라 전체가 다 높아야 이길 수 있음.
//합계가 높으면서 각각의 값도 높아져야함.
//18:26분 시간초과

//아이디어1: 결국은 가장 큰 값을 건너뛰고 싶을 것.합계가 가장 높은 사람을 건너뛰면 답이 나올까?
//18:37분 포기
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, k;

int soldier[100][3];
int cache[101][3][100];

//완전 탐색
int leastStatPoint(int idx, int pass)
{
	if (idx > n)
	{
		if (pass > 0)
			return INF;
		int result = 0;
		for (int i = 0; i < 3; ++i) {
			//패스를 하고 온 값이 가장 낮을 것이다.
			result += cache[idx-1][i][0];
		}
		return result;
	}

	for (int i = 0; i < 3; ++i) {
		int pstat;
		int nstat;
		pstat = cache[idx-1][i][pass];
		nstat = soldier[idx-1][i];
		cache[idx][i][pass] = max(pstat, nstat);
		if(pass > 0)
			cache[idx][i][pass-1] = pstat;
	}
	if (pass > 0)
		return min(leastStatPoint(idx+1, pass - 1), leastStatPoint(idx+1, pass));
	return leastStatPoint(idx+1, pass);
}


int main() {

	cin >> n >> k;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) {
			cin >> soldier[i][j];
			sum += soldier[i][j];
		}
		vec.push_back(make_pair(sum, i));
	}

	//합계순으로 정렬해서 가장 값이 높은 것을 제외한다.
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n - k; ++i)
		vec.pop_back();

	int str = 0, dex = 0, intel = 0;
	//남은 병사들 중의 가장 높은 스탯을 진수의 스탯에 대입한다.
	for (auto sol : vec)
	{
		str = max(str, soldier[sol.second][0]);
		dex = max(dex, soldier[sol.second][1]);
		intel = max(intel, soldier[sol.second][2]);
	}

	cout << str + dex + intel;
	//cout << leastStatPoint(1, n - k);
}