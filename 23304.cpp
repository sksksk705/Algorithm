#include <bits/stdc++.h>
#include <string>


using namespace std;
string s;
bool check_pal(int start, int end) {
	if (start == end)
		return true;
	int size = end - start+1;
	int mid = (start + end) / 2;
	int left;
	int right;
	if (size % 2)
	{
		left = mid - 1;
		right = mid + 1;
	}
	else
	{
		left = mid;
		right = mid+1;
	}
	for (int i = 0; i < size/2; ++i)
	{
		if (s[left - i] != s[right + i])
			return false;
	}
	return (check_pal(start, left) && check_pal(right, end));
}

int main() {

	cin >> s;

	if (check_pal(0,s.size()-1))
		cout << "AKARAKA";
	else
		cout << "IPSELENTI";
}