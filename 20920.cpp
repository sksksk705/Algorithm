//20920 ���ܾ� �ϱ�� ���ο�
//���ı���
//1. ��, 2. ����, 3. ������ ���̰� M���ϸ� ����.

//ó�� ����: 
// �ؽ����� ���� �󵵸� �ø���
// ���Լ��� ����� ���� ���� ������ �����
// vector�� sort�Ͽ� ���
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> s1, pair<int, string> s2) {
	if (s1.first == s2.first)
	{
		if (s1.second.size() == s2.second.size())
		{
			return s1.second < s2.second;
		}
		else
			return s1.second.size() > s2.second.size();
	}
	else
		return s1.first > s2.first;
		
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> freq;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s.size() < m)
			continue;
		freq[s]++;
	}
	vector<pair<int, string>> note;
	for (auto word : freq) {
		note.push_back(make_pair(word.second, word.first));
	}
	sort(note.begin(), note.end(),cmp);
	for (auto word : note) {
		cout << word.second<<'\n';
	}
	return 0;
}