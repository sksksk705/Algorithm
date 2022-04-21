//2022_04_21 ��������Ǯ��
//2602�� ���ٸ��ǳʱ�

//�ð� 1�� �޸� 128mb
//dp��� �������� ������?
//
#include <bits/stdc++.h>

using namespace std;

string magic;
string bridge[2];
int length;
int cache[102][22][2];

//start: �ٸ� �� ������ġ
//letter: �η縶���� ��� ° ����
//on: ���� õ�� or �Ǹ�
int cross(int start, int letter ,bool on) {
	//�κй��� �ذ�
	int& ret = cache[start+1][letter+1][on];
	if (ret != -1)
		return ret;
	ret = 0;

	//�������1:������ ���ڸ� ��Ҵ�.
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