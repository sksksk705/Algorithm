//2022_03_26 동적계획법
//23560 약

//아이디어: 아침은 아침, 저녁을 먹을 수 있음, 점심은 점심만 먹기 가능

#include<bits/stdc++.h>

using namespace std;

int cache[15][3][2][2];
int n;

//현재 날짜, 현재 시간(0 아침, 1 점심, 2 저녁), 전에 먹은 방향(0 앞, 1뒤) , 전전에 먹은 방향(0 앞, 1뒤)
int eatPill(int days, int time, int front, int prev)
{
	//기저사례1: 모든 약을 다 먹었음.
	if (days >= n)
		return 1;
	int& ret = cache[days][time][front][prev];
	if (ret != -1)
		return ret;
	if (time == 0) {
		//어제 점심과 저녁이 같은 날의 것을 먹었다면 앞, 뒤 아무거나 상관없음
		if (prev == front)
			ret = eatPill(days, 1, 1, front) + eatPill(days, 1, 1, front);
		//어제 점심과 저녁이 다른 날의 것을 먹었다면 어제 점심에 먹은 방향 밖에 먹을 수 없음
		else
			ret = eatPill(days, 1, prev, front);
	}
	if (time == 1) {
		//아침에 먹은 방향만 먹어야함
		ret = eatPill(days, 2, front, front);
	}
	if (time == 2) {
		//저녁엔 앞 뒤 아무거나 먹어도 된다.
		ret = eatPill(days+1, 0, 0, front) + eatPill(days+1, 0, 1, front);
	}
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	//다른 것을 먹었다고 가정
	cout << eatPill(0, 0, 0,1);
}