//2022_03_27 랜덤문제풀이
//1242번 소풍 골드2

//19:44분시작
//처음봤을 때는 오세푸스 문제처럼 list로 풀가 했는데 n,k가 최대 500만이라 안 될 거 같음
//iterator로 하면 되지 않을까?
//vector로 해봤는데 erase의 시간이 너무 오래 걸리는 것 같음

//아이디어: 선택한 숫자의 idx를 만들고 그 앞에 아이가 사라질 때마다 idx를 하나씩 줄인다.
//			한번 숫자를 삭제할 때마다 전체 크기도 1씩 줄인다. 삭제해야하는 idx와 m의 idx가 같을 때
//			결과를 출력한다.
//21:06분 정답
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> k >> m;
	int ans = 0;
	int erase_idx = 0;
	//현재 위치의 숫자가 1을 외치기 때문에 실제 움직이는 거리는 k-1;
	//반복문을 돌면서 전체크기를 1씩 줄이고 m보다 앞에 숫자가 삭제되면 m의 idx를 1씩 줄여줌
	//m의 idx와 삭제해야하는 idx가 같을 때 반복문 종료
	k--;m--;
	while (true) {
		ans++;
		if (erase_idx + k >= n)
			erase_idx = (erase_idx + k) % n;
		else
			erase_idx += k;
		if (m == erase_idx)
			break;
		if (erase_idx < m)
			m--;
		n--;

	}
	cout << ans;
	return 0;
}