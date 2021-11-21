#include <bits/stdc++.h>

using namespace std;

//이진탐색 구현
/*int binarySearch(vector<int> vec, int start, int end, int num) {  
	int _mid = (start + end) / 2;

	if (start > end)
		return 0;
	if (vec[_mid] == num)
		return 1;
	if (num < vec[_mid]) {
		return binarySearch(vec, start, _mid-1, num);
	}
	else {
		return binarySearch(vec, _mid+1, end, num);
	}
}*/

int main() {
	int n, m;
	cin >> n;
	vector<int> a1, a2;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		a1.push_back(num);
	}

	sort(a1.begin(), a1.end());
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> num;
		a2.push_back(num);
	}
	/* 기본적인 탐색방법
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j == n) {
				cout << 0<<"\n";
				break;
			}
			if (a2[i] == a1[j]) {
				cout << 1<<"\n";
				break;
			}
		}
	}
	직접 구현한 이진탐색 사용
	for (int i = 0; i < m; ++i) {
		int result = binarySearch(a1, 0, a1.size()-1, a2[i]);
		cout << result<<"\n";
	}
	*/
	//stl 사용
	for (int i = 0; i < m; i++) {
		cout<<binary_search(a1.begin(), a1.end(), a2[i])<<"\n";
	}
}

