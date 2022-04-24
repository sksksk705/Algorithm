//2022_04_24 랜덤문제풀이
//1111번 IQ Test

//77프로 틀렸습니다...
#include <bits/stdc++.h>

using namespace std;

int seq[51];
int n;
const int MAX = 987654321;

int findFunc()
{
	//a1, a2에 대하여
	//a가 -10000부터 10000까지 경우의 수를 모두 구한다.
	vector<pair<int, int>> abp;
	for (int a = -100000; a <= 100000; ++a)
	{
		int b = seq[1] - a * seq[0];
		abp.push_back(make_pair(a, b));
	}

	int reala = 0,realb = -1;
	//a2,a3에 대하여
	//그 중에 맞는 경우의 수를 저장한다.
	for (auto ab : abp)
	{
		if (seq[1] * ab.first + ab.second == seq[2]) {
			reala = ab.first;
			realb = ab.second;
			break;
		}
	}

	//모든 수열에 대해 맞는 경우의 수를 대입해보고 하나라도 틀리면 MAX를 반환한다.
	for (int i = 1; i < n; ++i)
	{
		if (seq[i-1] * reala + realb != seq[i])
			return MAX;
	}

	//모든 수열에 대해 정답이라면 다음 숫자를 반환한다.
	return seq[n - 1] * reala + realb;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	
	//수가 1개면 경우의 수는 무수히 많다.
	if (n == 1) {
		cout << "A";
		return 0;
	}

	//수열의 길이가 2 이하
	if (n <= 2) {
		//a1과 a2이 같은 수면 다음수도 같은 수여야 함.
		if (seq[0] == 1 && seq[1] == 0) {
			cout << seq[0];
			return 0;
		}
		//a1과 a2가 다르면 수는 무수히 많다.
		cout << "A";
		return 0;
	}

	//그 외의 후보를 찾는다.
	int result = findFunc();
	if (result == MAX)
		cout << "B";
	else
		cout << result;
}