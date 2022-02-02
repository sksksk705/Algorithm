#include <bits/stdc++.h>
#include <string>


using namespace std;

bool check_pal(string s,int depth, bool isodd) {
	depth++;
	if (s.size() == 1) //���̰� 1�̸� �Ӹ�����̴�.
		return true;
	if (depth == 3) //2���� �����ϸ� �Ǳ� ������ ���̰� 3�̸� �����.
		return true;

	int size = s.size() / 2;

	if (isodd) {
		for (int i = 1; i <= size; ++i) {
			if (s[size - i] == s[size + i]) //�Ӹ���� üũ
				continue;
			return false;
		}
		if (check_pal(s.substr(0, size), depth, size % 2) && 
			check_pal(s.substr(size+1, s.size()), depth, size % 2)) //���λ� ���̻� �Ӹ���� üũ
			return true;
	}
	else {
		int left = size - 1;
		int right = size;
		for (int i = 0; i < size; ++i) {
			if (s[left-i] == s[right+i]) //�Ӹ���� üũ
				continue;
			return false;
		}
		if (check_pal(s.substr(0,size), depth, size % 2) && check_pal(s.substr(right, s.size()), depth, size % 2)) //���λ� ���̻� �Ӹ���� üũ
			return true;
	}

	return false; //��� ���ϸ� �Ӹ������ �ƴ�.
}

int main() {
	string s;
	cin >> s;

	if (check_pal(s, 0, s.size() % 2))
		cout << "AKARAKA";
	else
		cout << "IPSELENTI";
}