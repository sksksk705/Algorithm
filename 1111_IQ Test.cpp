//2022_04_24 ��������Ǯ��
//1111�� IQ Test

//77���� Ʋ�Ƚ��ϴ�...
#include <bits/stdc++.h>

using namespace std;

int seq[51];
int n;
const int MAX = 987654321;

int findFunc()
{
	//a1, a2�� ���Ͽ�
	//a�� -10000���� 10000���� ����� ���� ��� ���Ѵ�.
	vector<pair<int, int>> abp;
	for (int a = -100000; a <= 100000; ++a)
	{
		int b = seq[1] - a * seq[0];
		abp.push_back(make_pair(a, b));
	}

	int reala = 0,realb = -1;
	//a2,a3�� ���Ͽ�
	//�� �߿� �´� ����� ���� �����Ѵ�.
	for (auto ab : abp)
	{
		if (seq[1] * ab.first + ab.second == seq[2]) {
			reala = ab.first;
			realb = ab.second;
			break;
		}
	}

	//��� ������ ���� �´� ����� ���� �����غ��� �ϳ��� Ʋ���� MAX�� ��ȯ�Ѵ�.
	for (int i = 1; i < n; ++i)
	{
		if (seq[i-1] * reala + realb != seq[i])
			return MAX;
	}

	//��� ������ ���� �����̶�� ���� ���ڸ� ��ȯ�Ѵ�.
	return seq[n - 1] * reala + realb;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	
	//���� 1���� ����� ���� ������ ����.
	if (n == 1) {
		cout << "A";
		return 0;
	}

	//������ ���̰� 2 ����
	if (n <= 2) {
		//a1�� a2�� ���� ���� �������� ���� ������ ��.
		if (seq[0] == 1 && seq[1] == 0) {
			cout << seq[0];
			return 0;
		}
		//a1�� a2�� �ٸ��� ���� ������ ����.
		cout << "A";
		return 0;
	}

	//�� ���� �ĺ��� ã�´�.
	int result = findFunc();
	if (result == MAX)
		cout << "B";
	else
		cout << result;
}