#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string s;
bool used[100000];

int make30(int num_used, int final_num)
{
	int ret = -1;
	if (num_used == s.size()&&final_num % 30 == 0)
	{
		return final_num;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (!used[i]) {
			used[i] = true;
			ret = max(make30(num_used + 1, final_num + (s[i]-'0') * pow(10, s.size() - num_used-1)),ret);
			used[i] = false;
			if (ret != -1)
				return ret;
		}
	}
	return ret;
}

int main()
{
	cin >> s;
	int result = make30(0, 0);
	cout << result;
}