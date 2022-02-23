#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string big;
string small;
string now;
vector<char> unequal;
bool used[10];
int k;

bool bigger(const string& s1, const string& s2, int idx)
{
	for (int i = 0; i <= idx; ++i)
	{
		if (s1[i] > s2[i])
			return true;
		if (s1[i] < s2[i])
			return false;
	}
	return false;
}

void burteForce(int idx)
{
	if (idx == k) {
		if (bigger(now, big,k))
			big = now;
		if (bigger(small,now,k))
			small = now;
		return;
	}
	for (char i = '0'; i <= '9'; ++i)
	{
		if (used[i - '0'])
			continue;
		if (unequal[idx] == '<')
		{
			if (i <= now[idx])
				continue;
		}
		else if (unequal[idx] == '>')
		{
			if (i >= now[idx])
				continue;
		}
		if (bigger(big, now, idx) && bigger(now, small, idx))
			continue;
		used[i - '0'] = true;
		now += i;
		burteForce(idx+1);
		now.pop_back();
		used[i - '0'] = false;
	}
}

int main()
{
	big = "000";
	small = "999";
	cin >> k;
	for(int i = 0; i < k;++i)
	{
		char sign;
		cin >> sign;
		unequal.push_back(sign);
	}
	for (int i = '0'; i <= '9'; ++i)
	{
		used[i - '0'] = true;
		now += i;
		burteForce(0);
		now.clear();
		memset(used, 0, sizeof(used));
	}

	cout << big << '\n' << small;
}