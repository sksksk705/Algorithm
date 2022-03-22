//2022_03_22 랜덤문제풀이
//5052 전화번호 목록

//아이디어1: 
//길이를 기준으로 sort하고 길이set을 만듦
//소트된 vec의 idx보다 작은 길이만큼 for문으로 찾음
//없다면 해쉬맵에 해당 수 추가. 한번만 나오니 set을사용
//만약 길이가 같다면 비교하지 않아도 됨.

//최대 500만번의 연산으로 처리가능
//-정답

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool cmp(const string& s1,const  string& s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	return s1.size() < s2.size();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		unordered_set<string> hash;
		int n;
		cin >> n;
		set<int> numlength;
		vector<string> nums(n);
		for (int i = 0; i < n; ++i) {
			string num;
			cin >> num;
			nums[i] = num;
		}
		//길이, 사전 순서대로 정렬
		sort(nums.begin(), nums.end(), cmp);

		//길이set 생성
		for (auto num : nums)
			numlength.insert(num.size());

		bool isConsistent = true;
		for (int i = 0; i < n; ++i) {
			int nowLength = nums[i].size();
			for (auto length : numlength) {
				//현재길이가 접두사의 길이와 같다면 비교 X (같은 숫자는 등장하지 않음)
				if (nowLength <= length)
					continue;

				//접두사가 전에 등장했었는지 탐색
				string head = nums[i].substr(0, length);

				//등장했다면 일관적이지 않다.
				if (hash.find(head) != hash.end()) {
					isConsistent = false;
					break;
				}
			}
			if (!isConsistent)
				break;
			//탐색종료 후 해시에 현재 수 추가
			hash.insert(nums[i]);
		}
		if (isConsistent)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}