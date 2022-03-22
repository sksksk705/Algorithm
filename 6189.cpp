//6189 ���� ���� �ٹ̱�
//O(n2)���δ� ���� Ǯ�� ������ n�� 80000�̱� ������ �ٸ� ����� ����ؾ���
//���̵��:
//������ ����Ѵ�.
//���� ���̺��� ���� �������� pop�Ѵ�.
//���纸�� ���� ������ ���� ��������ŭ(������ ũ�⸸ŭ) ������� ���Ѵ�.
//stack�� ���� ���̸� push�Ѵ�.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	//1�� �Ǽ�: ������ ����� ���� int�� ������ �پ� ���� (79999 + 0) * 80000 /2(�׷��� ����);
	long long result = 0;
	cin >> n;
	stack<int> roottop;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		//2�� �Ǽ�: ���� ������ �� �� ����(����)
		while (!roottop.empty() && roottop.top() <= h)
			roottop.pop();
		result += roottop.size();
		roottop.push(h);
	}
	cout << result;
}