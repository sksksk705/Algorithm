//2022_03_25 랜덤문제풀이
//16501 만족도 점수

//완전탐색일까? 값을 계산해놓을 수는 있음
//12, 34 == 34,12 즉 조합을 찾는 것
//정렬되어있는 조합만 찾으면 됨
//8개의 숫자가 다 사용되어야하기 때문에 1이 가장 앞에 있는 경우만 탐색하면 됨
//생각이 안 남...내일 몸 좀 좋아지면 해보자 20:49분
double ability[8][8];
bool played[8];

#include <bits/stdc++.h>

using namespace std;

int main() {
	for (int i = 0; i < 8; ++i)
			cin >> ability[i][i];

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			ability[i][j] = (ability[i][i] + ability[j][j]) / 2;
			ability[j][i] = ability[i][j];
		}
	return 0;
}