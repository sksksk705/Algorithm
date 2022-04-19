//2022_04_19 랜덤문제풀이
//2632번 피자판매

//아이디어 각 피자에서 가능한 경우의 수를 다 만들어놓고
//각각의 경우의 수를 더한다.
//시간복잡도: 0(n2 + m2 + k) = 최대 400만번
#include <bits/stdc++.h>

using namespace std;


int customer;
int m, n;
int A[1001];
int B[1001];
int psumA[1000001];
int psumB[1000001];

void eatPizza(int start, bool Apizza)
{
	if (Apizza) {
		int piece = A[start];
		psumA[piece]++;
		int next = (start + 1) % m;
		//한칸 띄우고
		while ((next+1)%m != start)
		{
			piece += A[next];
			psumA[piece]++;
			next = (next + 1) % m;
		}
		psumA[piece + A[next]] = 1;
	}
	else {
		int piece = B[start];
		psumB[piece]++;
		int next = (start + 1) % n;
		while ((next + 1) % n != start)
		{
			piece += B[next];
			psumB[piece]++;
			next = (next + 1) % n;
		}
		psumB[piece + B[next]] = 1;
	}
}

int main() {
	cin >> customer;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		cin >> A[i];
	for (int i = 0; i < n; ++i)
		cin >> B[i];

	psumA[0] = 1;
	psumB[0] = 1;

	for (int i = 0; i < m; ++i)
		eatPizza(i, true);

	for (int i = 0; i < n; ++i)
		eatPizza(i, false);

	int ret = 0;
	for (int i = 0; i <= customer; ++i)
	{
		ret += psumA[i] * psumB[customer - i];
	}
	cout << ret;
}