//2022_03_31 ������ȹ�� ������ ������ ����ϱ�
//14002 ���� �� �����ϴ� �κ� ����4

//dp�� ���� ���ϸ鼭 �����ظ� �����ߴٰ� ���� �Լ��� ����ϱ�
#include <bits/stdc++.h>

using namespace std;

int seq[1001], choice[1001], cache[1001];
int n;
int LIS(int idx) {
	int& ret = cache[idx+1];
	if (ret != -1)
		return ret;
	ret = 1;
	int bestNext = -1;
	for (int i = idx + 1; i < n; ++i) {
		if (idx == -1 || seq[i] > seq[idx]) {
			int cand = LIS(i)+1;
			if (cand > ret)
			{
				bestNext = i;
				ret = cand;
			}
		}
	}
	choice[idx + 1] = bestNext;
	return ret;
}

void reconstruct(int start, vector<int>& ans) {
	if (start != -1) ans.push_back(seq[start]);
	int next = choice[start + 1];
	if (next != -1) reconstruct(next, ans);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	memset(cache, -1, sizeof(cache));
	memset(choice, -1, sizeof(choice));
	int result = LIS(-1)-1;
	cout << result << '\n';
	vector<int> ans;
	reconstruct(-1, ans);
	for (auto elem : ans)
		cout << elem << " ";
}