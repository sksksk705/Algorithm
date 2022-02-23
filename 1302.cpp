#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> book_list;
	for (int i = 0; i < n; ++i)
	{
		string book;
		cin >> book;
		auto item = book_list.find(book);
		if (item == book_list.end()) {
			book_list.emplace(book, 1);
		}
		else
		{
			(item->second)++;
		}
	}
	auto maxsold = book_list.begin();
	for (auto it = ++book_list.begin(); it != book_list.end(); ++it)
	{
		if (maxsold->second < it->second)
			maxsold = it;
	}
	cout << maxsold->first;

}