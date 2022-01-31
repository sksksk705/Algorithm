#include <bits/stdc++.h>
//�׸��� ������ �� x,y���� �˰� �Լ��� ��Ȯ�� �������־�� ��.
using namespace std;


short original_file[64][64];
short IsSameColor(int x, int y, int size)
{
	short head = original_file[y][x]; //ù��°�� y ��, �ι�°�� x��
	if (size == 1)
		return head;
	for (int i = y; i < y+size; ++i)
	{
		for (int j = x; j < x+size; ++j)
		{
			if (original_file[i][j] != head)
				return -1;
		}
	}
	return head;
}
string quad_tree(int x, int y, int size)
{
	string ans;
	short result = IsSameColor(x, y, size);
	if (result != -1) {
		ans = char(result); 
		return ans;
	}
	else {
		ans += '(';
		int half = size / 2;
		ans += quad_tree( x, y, half);
		ans += quad_tree( x + half, y, half);
		ans += quad_tree( x, y + half, half);
		ans += quad_tree( x + half, y + half, half);
		ans += ')';
	}
	return ans;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			original_file[i][j] = s[j]; //ù��°�� y ��, �ι�°�� x��
		}
	}
	string ans = quad_tree(0, 0, n);
	cout << ans;
}