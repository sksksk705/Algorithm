#include <bits/stdc++.h>

using namespace std;
int n;
int broken[10];
vector<int> button;

int brute(int now, int posi) {
	int ret = 987654321;
	if (posi > 6)			//한계를 차라리 뺴는 것이 더 계산에 이로움
		return abs(n - now)+posi;
	for (int i = 0; i < button.size(); ++i) {
		if (now == -1) {
			ret = min(ret, brute(button[i], posi + 1));
		}
		else {
			ret = min(ret, abs(n - now) + posi);
			ret = min(ret, brute(now + button[i] * pow(10, posi), posi + 1));
		}
	}
	return ret;
}


int main() {
	cin >> n;
	int brokenButton;
	cin >> brokenButton;
	for (int i = 0; i < brokenButton; ++i) { 
		int num;
		cin >> num;
		broken[num] = true;
	}
	for (int i = 0; i < 10; ++i) {
		if (!broken[i])
			button.push_back(i);
	}
	int ans = 0;
	ans = min(abs(n - 100), brute(-1, 0));
	cout << ans;
}