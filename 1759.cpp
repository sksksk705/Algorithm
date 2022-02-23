#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<char> cons;
vector<char> vowel;
const string CONS = "aeiou";
vector<char> passWord;
int L, C;
const int minCons = 1;
const int minVowel = 2;
void makePassword(int nowC, int nowV, int nowL, int considx, int vowelidx)
{
	if (nowL == L && nowC >= minCons && nowV >= minVowel)
	{
		for (auto p : passWord)
			cout << p;
		cout << '\n';
		return;
	}
	while (considx < cons.size() || vowelidx < vowel.size())
	{
		char _c, _v;
		_c = _v = CHAR_MAX;
		if (considx != cons.size())
			_c = cons[considx];
		if (vowelidx != vowel.size())
			_v = vowel[vowelidx];
		if (_c < _v)
		{
			if (passWord.empty() || _c > passWord.back())
			{
				passWord.push_back(_c);
				makePassword(nowC + 1, nowV, nowL + 1, considx + 1, vowelidx);
				passWord.pop_back();
				considx++;
			}
		}
		else
		{
			if (passWord.empty() || _v > passWord.back())
			{
				passWord.push_back(_v);
				makePassword(nowC, nowV+1, nowL + 1, considx, vowelidx+1);
				passWord.pop_back();
				vowelidx++;
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		char c;
		cin >> c;
		if (CONS.find(c) != string::npos)
		{
			cons.push_back(c);
		}
		else
			vowel.push_back(c);
	}
	sort(cons.begin(), cons.end());
	sort(vowel.begin(), vowel.end());
	makePassword(0, 0, 0, 0, 0);
}