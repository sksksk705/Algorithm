#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> nums_by_head;
struct cmp1 {
	bool operator()(const string& s1, const string& s2)	//비교하는 방법!
	{
		return s1 + s2 > s2 + s1;
	}
};

int n, k;

int main() {
	cin >> k >> n;
	nums_by_head.reserve(50);
	int max_length = 0;
	for (int i = 0; i < k; ++i)
	{
		string s;
		cin >> s;
		if (s.size() > max_length)
			max_length = s.size();
		nums_by_head.push_back(s);
	}
	sort(nums_by_head.begin(), nums_by_head.end(), cmp1());
	string result = "";
	for (auto s : nums_by_head)
	{
		result += s;
		if (s.size() == max_length) {
			for (int i = 0; i < n - k; ++i)
			{
				result += s;
			}
			max_length = 0;
		}
	}
	cout << result;
	return 0;
}
