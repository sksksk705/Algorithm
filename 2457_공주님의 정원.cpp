//2022_04_19 ��������Ǯ��
//2457�� ���ִ��� ����

//�� 365��
//���������� ��,���� ��¥�� ���� �� �������� �������� ����
//������ ���� �������� ���� ���� �Ǿ����� �� �ִ� ���� ����
//Greedy + �ڷᱸ��
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
	//3�� 1�Ϻ��� ����
	int date = pSum[2]+1;
	int ret = 0;

	//11�� 30�� ���� 11�� 30�Ͽ� ���� ���� �� ��.
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
		//������ ���� �������� �Ǵ� ���� ����.
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