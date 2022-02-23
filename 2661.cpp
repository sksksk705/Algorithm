#include <iostream>

#define FASTIO			ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;

int n;
int seq[80];
bool isGoodSeq(int idx)
 {
	for (int i = 0; i < idx -1; ++i)
	{
		for (int j = 1; j + i + j <= idx; ++j)
		{ 
			int same_seq = 0;
			for (int k = 0; k < j; ++k)
			{
				if (seq[i + k] == seq[i + j + k])
					same_seq++;
				if (same_seq == j)
					return false;
			}
		}
	}
	return true;
}

void makeGoodSeq(int idx)
{
	if (idx == n)
		throw idx;
	for (int i = 1; i <= 3; ++i)
	{
		seq[idx] = i;
		if(isGoodSeq(idx+1))
			makeGoodSeq(idx + 1);
		seq[idx] = 0;
	}
}

int main()
{
	FASTIO;
	cin >> n;

	try {
		makeGoodSeq(0);
	}
	catch (...)
 	{
		for (int i = 0; i < n; ++i)
		{
			cout << seq[i];
		}
		return 0;
	}
	return 0;
}