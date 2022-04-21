//2022_04_21 랜덤문제풀이
//2602번 돌다리건너기

//시간 1초 메모리 128mb
//dp사용 가능하지 않을까?
//
#include <bits/stdc++.h>

using namespace std;

string magic;
string bridge[2];
int length;
int cache[102][22][2];

//start: 다리 위 현재위치
//letter: 두루마리의 몇번 째 글자
//on: 현재 천사 or 악마
int cross(int start, int letter ,bool on) {
	//부분문제 해결
	int& ret = cache[start+1][letter+1][on];
	if (ret != -1)
		return ret;
	ret = 0;

	//기저사례1:마지막 문자를 밟았다.
	if (letter == magic.size()-1)
		return ret = 1;

	bool nextbridge = !on;
	int nextletter = letter + 1;
	for (int i = start + 1; i < length; ++i)
	{
		if (start == -1)
		{
			if (bridge[0][i] == magic[nextletter])
				ret += cross(i, nextletter, 0);
			if (bridge[1][i] == magic[nextletter])
				ret += cross(i, nextletter, 1);
		}
		else if (bridge[nextbridge][i] == magic[nextletter])
			ret += cross(i, nextletter, nextbridge);
	}
	return ret;
}

int main() {
	cin >> magic;
	cin >> bridge[0];
	cin >> bridge[1];
	length = bridge[0].size();
	memset(cache, -1, sizeof(cache));
	int result = cross(-1, -1, 0);
	cout << result;
}