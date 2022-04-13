//2022_04_13 랜덤문제풀이
//1484번 다이어트

//시간 2초, 메모리 128MB
//입력 10만
//x2 - y2 = G;
//x2 - (x-1)2 <= G일 때만 확인하면 됨
//목표: 가능한 현재 모든 현재 몸무게 - 경우의 수
#include <bits/stdc++.h>

using namespace std;

int main() {
	int G;
	cin >> G;
	int x = ceil(sqrt((double)G));
	int y = 0;
	double realy = 0.0;
	int total = 0;
	while (x <= (G + 1)/2)
	{
		//y가 자연수일 때
		y = realy = sqrt(pow(x, 2) - G);
		if (y == realy && y != 0) {
			cout << x << '\n';
			total++;
		}
		x++;
	}
	if (total == 0)
		cout << -1;
}