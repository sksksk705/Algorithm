//2022_03_28 ���׹���Ǯ��
//2467 ���

//2���� ���� �ִ� 20������ int�� ����� �� ����
//�� 10������ �Է��� �־����� ����Ž���� ������ ��� 10���� �߿� 2���� ���� ������ ����ŭ
//������ �ؾ��ϱ� ������ ����Ž���� �Ұ�.

//�Ѱ��� ��Ʈ�� ���ĵǾ��ִٴ� ��. �̺�Ž���� ����غ���?
//13�� 54�� ����
#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000001;
int solution[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> solution[i];
	}
	int value = INF;
	int smallOne = -1;
	int bigOne = 100001;
	for (int start = 0; start < n; ++start) {
		int hi = n-1, lo = 0;
		if (solution[start] < 0)
			lo = start + 1;
		else
			hi = start - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int startValue = solution[start] + solution[mid];
			if (abs(startValue) < value) {
				smallOne = solution[start] < solution[mid] ? solution[start] : solution[mid];
				bigOne = solution[start] > solution[mid] ? solution[start] : solution[mid];
				value = abs(startValue);
			}
			if (startValue < 0)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		//cout << "[" << start << "]" << '\n';
		//cout << smallOne << " " << bigOne << '\n';
		//cout << value << "\n\n";
	}
	cout << smallOne << " " << bigOne;
}