//2022_04_07 랜덤문제풀이
//23559 밥

//1000단위로 전개가 되니 5,1로 메뉴가격;
//N이 10만 X가 최대 5억, 수가 너무 크니까 그리디를 써야할 듯 
//1000원은 언제든 먹을 수 있다. 단 5000원짜리는 5000원이상일 때만 먹을 수 있다.
//1000원 대신 5000원을 먹으면 4000원을 더 내야함. 남은 4000원의 수만큼 차이가 큰 애들을 먹자
//1000원이 더 맛있을 때는 1000원을 먹자
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return (p1.first - p1.second > p2.first - p2.second);
}

int main() {
	int n, x;
	cin >> n >> x;
	x /= 1000;
	
	vector<pair<int, int>> food;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		int A, B;
		cin >> A >> B;
		total += B;
		food.push_back(make_pair(A, B));
	}

	sort(food.begin(), food.end(), cmp);
	int canEatA = (x - n) / 4;
	for (int i = 0; i < canEatA; ++i) {
		if (food[i].first <= food[i].second)
			break;
		total -= food[i].second;
		total += food[i].first;
	}
	cout << total;

}