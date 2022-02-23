#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		st.emplace(k);
	}
	for (auto elem : st)
	{
		cout << elem << ' ';
	}
}