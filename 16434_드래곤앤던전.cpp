//2022_04_18 랜덤문제풀이
//16434번 드래곤 앤 던전

//시간 1초, 메모리 256mb 힌트는 없다
//목표 최소 H -> 최적화
//예제출력을 보니 결과가 int 범위는 가뿐히 넘는 것 같다.
//예제 2번 같은 방이 12만개가 있으면 범위가 말이 안 되는데...?
//long long으로 모든 범위가 커버가능
#include <bits/stdc++.h>

using namespace std;

int n;
int dungeon[123456][3];
const long long INF = LLONG_MAX;
long long hpMax , hAtk;


long long clearDungeon()
{
	//ans: 마지막이 회복방으로 끝났을 때 그 전의 체력값을 저장해야함.
	long long ans = 0;
	for (int room = 0; room < n; ++room)
	{
		long long atk = dungeon[room][1];
		long long hp = dungeon[room][2];
		if (dungeon[room][0] == 2) {
			hpMax = hpMax - hp > 1 ? hpMax - hp : 1;
			hAtk += atk;
		}
		else
			//내가 받아야하는 데미지를 최대체력에 더함.
			hpMax += ((hp + hAtk - 1) / hAtk -1) * atk;
		ans = max(ans, hpMax);
	}
	return ans;
}

void input() {
	cin >> n >> hAtk;
	for (int i = 0; i < n; ++i)
	{
		cin >> dungeon[i][0] >> dungeon[i][1] >> dungeon[i][2];
	}
	hpMax = 1;
}


int main() {
	input();
	cout << clearDungeon();
}
