#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> country;
int n;
int profit;
int moneyneed = 0;

int findMaxProfit()
{
	int start = profit/n;
	int end = country.back();
	int paid = 0;
	if (profit >= moneyneed)
		return end;
	while (start >= country[paid])
	{
		profit -= country[paid];
		paid++;
		start = profit / (n - paid);	
	}
	return start;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		moneyneed += c;
		country.push_back(c);
	}
	cin >> profit;
	sort(country.begin(), country.end());
	int result = findMaxProfit();
	cout << result;
}