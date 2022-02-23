#include <bits/stdc++.h>

using namespace std;

int Card(int n)
{
	queue<int> deck;
	for (int i = 1; i <= n; i++)
	{
		deck.push(i);
	}
	while (deck.size() > 1)
	{
		deck.pop();
		deck.push(deck.front());
		deck.pop();
	}
	return deck.front();
}

int main()
{
	int n;
	cin >> n;
	cout << Card(n);
}