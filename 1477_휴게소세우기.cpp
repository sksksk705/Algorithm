//2022_04_18 랜덤문제풀이
//1477번 휴게소 세우기

//시간2초, 메모리 128mb
//이분 탐색인데 마지막 휴게소에서 끝까지의 거리를 계산 안 했었음.
#include <bits/stdc++.h>

using namespace std;

vector<int> shelter;

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 0; i < n; ++i)
	{
		int shelt;
		cin >> shelt;
		shelter.push_back(shelt);
	}
	shelter.push_back(0);
	shelter.push_back(l);
	sort(shelter.begin(), shelter.end());

	int lo = 1, hi = l;
	while (lo < hi)
	{
		int numOfShel = 0;
		int mid = (lo + hi) / 2;
		for (int i = 1; i < shelter.size(); ++i)
			numOfShel += (shelter[i] - shelter[i - 1] + mid - 1)/ mid - 1;
		if (numOfShel <= m)
			hi = mid;
		else
			lo = mid+1;
	}
	cout << hi;
}