#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> vec;
int result;

void seqPlus(int now_num, int idx)
 {
	if (now_num == s && idx != -1)
	{
		result++;
	}
	for (int i = idx + 1; i < vec.size(); ++i)
	{
		seqPlus(now_num + vec[i], i);
	}
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		int elem; 
		cin >> elem;
		vec.push_back(elem);
	}
	seqPlus(0, -1);
	cout << result;
 }