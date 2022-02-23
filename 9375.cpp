#include <iostream>
#include <map>

using namespace std;
map<string, int> closet;

int combination()
{
	int result = 1;
	for (auto part : closet)
	{
		result *= (part.second + 1);
	}
	return result -= 1;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int clothes;
		cin >> clothes;
		closet.clear();
		for (int j = 0; j < clothes; ++j) {
			string name, part;
			cin >> name >> part;
			auto exist = closet.find(part);
			if (exist == closet.end())
			{
				closet.emplace(part, 1);
			}
			else
				closet[part]++;
		}
		int result = combination();
		cout << result << '\n';
	}
	return 0;
}