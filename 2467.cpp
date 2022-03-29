//2022_03_28 코테문제풀이
//2467 용액

//2개의 합은 최대 20억으로 int를 사용할 수 있음
//총 10만개의 입력이 주어지고 완전탐색을 진행할 경우 10만개 중에 2개를 고르는 조합의 수만큼
//연산을 해야하기 때문에 완전탐색은 불가.

//한가지 힌트는 정렬되어있다는 거. 이분탐색을 사용해볼까?
//13시 54분 정답
#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000001;
int solution[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> solution[i];
	}
	int value = INF;
	int smallOne = -1;
	int bigOne = 100001;
	for (int start = 0; start < n; ++start) {
		int hi = n-1, lo = 0;
		if (solution[start] < 0)
			lo = start + 1;
		else
			hi = start - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int startValue = solution[start] + solution[mid];
			if (abs(startValue) < value) {
				smallOne = solution[start] < solution[mid] ? solution[start] : solution[mid];
				bigOne = solution[start] > solution[mid] ? solution[start] : solution[mid];
				value = abs(startValue);
			}
			if (startValue < 0)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		//cout << "[" << start << "]" << '\n';
		//cout << smallOne << " " << bigOne << '\n';
		//cout << value << "\n\n";
	}
	cout << smallOne << " " << bigOne;
}