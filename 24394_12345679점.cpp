//2022_04_06 ��������Ǯ��
//24394�� 123456789��

//���̵��: �³�Ʈ 1���� �ּ� ������ 2�� 5õ & �³�Ʈ 1���� ���� ���ϴ� prefect�� ����
#include <bits/stdc++.h>

using namespace std;

const double MAX = 1000000000.0;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, S;
		cin >> N >> S;
		//1. Good ��Ʈ�� ���� ������ ���Ѵ�.
		//2. good�� ����: S / good �� ����.
		//3. perfect�� ����: S - (good�� ���� * good �� ����)
		//(�ִ� 20000���� ��Ʈ�� �ص� �´� �ּҰ��� 25000 a�� 20000���� �̱� ������ �˾Ƴ� �� �ִ�).
		//4. perfect*2�� good�� �������� ���ų� perfect�� N�� �������� ������ -1
		double pointPerGood = MAX /(2*N);
		int needGood = S / pointPerGood;
		double perfect = S - needGood * pointPerGood;
		if (perfect*2 > needGood || perfect > N)
			cout << -1;
		else
			cout << needGood << " " << round(perfect);
		cout << '\n';
	}
}