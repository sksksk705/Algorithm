//2022_04_19 ��������Ǯ��
//2632�� �����Ǹ�

//���̵�� �� ���ڿ��� ������ ����� ���� �� ��������
//������ ����� ���� ���Ѵ�.
//�ð����⵵: 0(n2 + m2 + k) = �ִ� 400����
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
		//��ĭ ����
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