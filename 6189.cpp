//6189 옥상 정원 꾸미기
//O(n2)으로는 쉽게 풀수 있지만 n이 80000이기 때문에 다른 방법을 고려해야함
//아이디어:
//스택을 사용한다.
//현재 높이보다 낮은 빌딩들을 pop한다.
//현재보다 전에 등장한 높은 빌딩수만큼(스택의 크기만큼) 결과값을 더한다.
//stack에 현재 높이를 push한다.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	//1번 실수: 가능한 경우의 수가 int의 범위를 뛰어 넘음 (79999 + 0) * 80000 /2(그래도 오답);
	long long result = 0;
	cin >> n;
	stack<int> roottop;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		//2번 실수: 같은 빌딩도 볼 수 없음(정답)
		while (!roottop.empty() && roottop.top() <= h)
			roottop.pop();
		result += roottop.size();
		roottop.push(h);
	}
	cout << result;
}