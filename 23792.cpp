//2022_03_23 랜덤 문제 풀이
//23792번 k번째 음식찾기

//21:35분 시작
//트리플 포인터로 3개를 비교하면서 하나씩 옮기면 되지 않을까?
//비교가 너무 많이 되서 차라리 하나로 뭉쳐서 sort한 뒤 초과된 음식이 나오면 그냥 continue하는 걸로
//22:18분 시간초과 아이디어: 차라리 배열로 300000 누적합을 3가지 
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> foods;
vector<int> idx;


void kndDelicous(int ko, int usa, int jp,int k)
{
	int foodlimit[3]{ ko,usa,jp };
	int foodpasses[3]{ 0,0,0 };
	int idx = 0, total = 0;
	int nowFood;
	//총 k개의 음식을 찾아보고 이미 초과된 음식종류면 total을 증가하지 않는다.
	//마지막 음식의 종류를 기억하여 해당 종류를 몇번 지나쳤는지 출력
	while (total < k) {
		nowFood = foods[idx++].second;
		if (foodpasses[nowFood] >= foodlimit[nowFood]) {
			continue;
		}
		foodpasses[nowFood]++;
		total++;
	}
	cout << foods[idx-1].second + 1 << ' ' << foodpasses[nowFood]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j){
			int food;
			cin >> food;
			foods.push_back(make_pair(food,i));
		}

	sort(foods.begin(), foods.end());
	int Q;
	cin >> Q;
	while (Q--)
	{
		int x, y, z, k;
		cin >> x >> y >> z >> k;
		kndDelicous(x, y, z, k);
	}
}