//2022_03_22 ��������Ǯ��
//3986 �����ܾ�

//���̵��: ���ÿ� ��ٰ� size�� 2�� �Ѿ��µ� top�� ���� ���ڿ� �ٸ��� x, ������ ���� pop�����ϸ� 0
//�Ǽ�1: ������� ������ �͸� �����, BABBAB ���� ������ �������� �ʾƵ� ������. 
//-����
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 0;
	while (n--) {
		stack<int> s;
		string str;
		cin >> str;
		for (auto c : str) {
			//��������
			if (!s.empty()) {
				//������� ������ ��
				if (s.top() == c)
					s.pop();
				else
					//��ġ�� �ʴ� ���� ������ ��
					s.push(c);
			}
			else
				//����ִٸ�
				s.push(c);
		}
		if (s.empty())
			result++;
	}
	cout << result;
}