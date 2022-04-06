//2022_04_05 랜덤문제풀이
//2166 다각형의 면적

//1. 반시계방향 순서로 각 꼭지점의 x와 y를 리스트로 나열하고 첫 꼭지점을 하나 더 추가
//2. 각 꼭지점의 x좌표를 다음 꼭지점의 y값과 곱하고 각 결과를 더한다.
//3. 각 꼭지점의 y좌표를 다음 꼭지점의 x값과 곱하고 더한다.
//4. 두번째 결과를 첫번째 결과에서 빼고 2로 나누면 끝!
#include <bits/stdc++.h>

using namespace std;

int main() {
	//순서대로 N개의 점이 주어지기 때문에 반대로 하면 반시계 방향 가능
	int n;
	cin >> n;
	vector<pair<long long, long long>> points;
	for (int i = 0; i < n; ++i) {
		long long x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	//리스트를 뒤집고 첫 꼭지점을 맨 뒤에 추가
	reverse(points.begin(), points.end());
	points.push_back(points.front());

	double xToy = 0;
	double yTox = 0;
	for (int i = 0; i < n; ++i) {
		xToy += points[i].first * points[i + 1].second;
		yTox += points[i].second * points[i + 1].first;
	}

	double result = (double)(xToy - yTox) / 2;
 	cout <<fixed<<setprecision(1)<< (round(result * 10)) / 10;
}