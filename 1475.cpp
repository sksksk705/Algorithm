#include <iostream>
#include <string>

using namespace std;

int have[10];
int s;
int main()
{
	string roomNumber;
	getline(cin, roomNumber);
	auto it = roomNumber.begin();
	while (it != roomNumber.end())
	{
		int needNum = *it - '0';
		it++;
		if (needNum == 6 || needNum == 9)
		{
			if (have[6] != 0) {
				have[6]--;
				continue;
			}
			else if (have[9] != 0) {
				have[9]--;
				continue;
			}
		}
		if (have[needNum] == 0)
		{
			s++;
			for (int i = 0; i < 10; ++i)
			{
				have[i]++;
			}
		}
		have[needNum]--;
	}
	cout << s;
}