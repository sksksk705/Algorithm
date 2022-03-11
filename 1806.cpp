#include <bits/stdc++.h>

using namespace std;
int MAX = 98765321;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> seq;
	for (int i = 0; i < n; ++i) {
		int seqi;
		cin >> seqi;
		seq.push_back(seqi);
	}
	int sum = 0;
	int shortest = MAX;
	int i = 0; int j = 0;
	while (j < n) {
		sum += seq[j];
		while (sum >= s) {
			shortest = min(shortest, j - i+1);
			sum -= seq[i];
			i++;
		}
		j++;
	}
	if (shortest == MAX)
		shortest = 0;
	cout << shortest;
	
}