//2022_04_19 랜덤문제풀이
//2457번 공주님의 정원

//총 365일
//누적합으로 월,일을 날짜로 변경 후 시작일을 기준으로 정렬
//마지막 꽃이 지기전에 가장 오래 피어있을 수 있는 꽃을 선택
//Greedy + 자료구조
#include <bits/stdc++.h>

using namespace std;

int month[13]{ 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
int pSum[13];

void preCal() {
	for (int i = 1; i <= 12; ++i)
	{
		pSum[i] = pSum[i - 1] + month[i];
	}
}

int gradening(vector<pair<int,int>>& flowers)
{
	queue<int> bloomQ;
	queue<int> fallQ;
	for (auto flower : flowers)
	{
		bloomQ.push(flower.first);
		fallQ.push(flower.second);
	}
	//3월 1일부터 시작
	int date = pSum[2]+1;
	int ret = 0;

	//11월 30일 포함 11월 30일에 꽃이 지면 안 됨.
	while (date <= pSum[11] && !bloomQ.empty())
	{
		int bloom = 0;
		int fall = 0;
		while (!bloomQ.empty())
		{
			bloom = bloomQ.front();
			if (bloom > date)
				break;
			fall = max(fall,fallQ.front());
			bloomQ.pop(); fallQ.pop();
		}
		//마지막 꽃이 지기전에 피는 꽃이 없다.
		if (fall == 0)
			break;
		date = fall;
		ret++;
	}
	if(date > pSum[11])
		return ret;
	return 0;
}

int main() {
	preCal();
	int n;
	cin >> n;
	vector<pair<int, int>> flowers (n);
	for (int i = 0; i < n; ++i) {
		int bm, bd, fm, fd;
		cin >> bm >> bd >> fm >> fd;
		int blooming = pSum[bm - 1] + bd;
		int falling = pSum[fm - 1] + fd;
		flowers[i] = make_pair(blooming, falling);
	}
	sort(flowers.begin(), flowers.end());
	cout<<gradening(flowers);
	return 0;
}