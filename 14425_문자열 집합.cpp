//2022_04_25 ���ڿ�
//14425�� ���ڿ� ����

//�ؽþ��� Ǯ���� ����.
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_set<string> dic;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		dic.emplace(str);
	}

	int ret = 0;
	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		if (dic.find(str) != dic.end())
			ret++;
	}

	cout << ret;
}