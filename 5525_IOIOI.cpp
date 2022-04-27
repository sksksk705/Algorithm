//2022_04_25 ���ڿ�
//5525�� IOIOI

//IOI�� ã�Ƽ� ������ִ� ������ N�� �̻��̸� ���信 �� ���̷� ���� �� �ִ� ��� �����ֱ�.

#include <bits/stdc++.h>

using namespace std;

const string target = "IOI";

int main() {
	int n, s;
	string str;
	cin >> n >> s >> str;

	vector<bool> ret(s,false);
	for (int i = 0; i < s-2; ++i) {
		//�ش� ��ġ���� IOI�� ���� �� �ִٸ� true;
		if (str[i] == 'I')
		{
			bool match = true;
			for (int j = 0; j < 3; ++j)
			{
				if (str[i + j] != target[j])
				{
					match = false;
					break;
				}
			}
			if (match)
				ret[i] = true;
		}
	}

	//ioiLen: ����Ǿ��ִ� IOI����
	//total: ���
	int ioiLen = 0;
	int total = 0;
	for (int i = 0; i < ret.size();i++) { 
		if (ret[i] == true) {
			ioiLen = 1;
			while (ret[i + 2] == true) {
				i += 2;
				ioiLen++;
			}
			//IOI�� n�� �̻� ����Ǿ� ���� �� ioiLen - n + 1����ŭ ���� �� �ִ�.
			if(ioiLen >= n)
				total += ioiLen - n + 1;
		}
	}

	cout << total;
}