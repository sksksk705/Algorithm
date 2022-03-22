//20920 영단어 암기는 괴로워
//정렬기준
//1. 빈도, 2. 길이, 3. 사전순 길이가 M이하면 제외.

//처음 생각: 
// 해쉬맵을 만들어서 빈도를 늘리고
// 비교함수를 만들어 위의 정렬 기준을 만들고
// vector를 sort하여 출력
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