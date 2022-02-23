#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1000000;
typedef long long LL;
bool squarenono[1000001];

LL IsNotSquare(LL _min, LL _max)
{
	for (int i = 0; i <= _max - _min + 1; ++i)
		squarenono[i] = true;
	LL result =_max - _min +1;
	LL i = 2;
	while (i * i <= _max)
	{
		LL sNum = _min / (i * i);
		if (_min % (i * i) != 0)
			sNum++;
		for (LL j = sNum * (i * i); j <= _max; j += i * i)
		{
			if (squarenono[j - _min])
			{
				squarenono[j - _min] = false;
				result--;
			}
		}
		i++;
	}
	return result;
}

int main()
{
	LL _min, _max;
	cin >> _min >> _max;
	LL result = IsNotSquare(_min, _max);
	cout << result;
}