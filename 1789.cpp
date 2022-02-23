#include <iostream>
#define FASTIO		ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
	long long s;
	cin >> s;
	int i = 0;
	while (s >= 0)
	{
		s -= ++i;
	}
 	cout << i-1;
}