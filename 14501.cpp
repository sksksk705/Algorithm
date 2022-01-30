// 14501 퇴사
// 완전 탐색
// 최악의 경우 매일 할지 말지 정하기 때문에 2**n 시간 복잡도
// 최대 15이기 때문에 32768개의 경우의 수

// 풀이:
// 해당일이 가능하다면 일을 하고 재귀호출 이익을 최대값과 비교한다.


#include <bits/stdc++.h>
using namespace std;

bool work[15];
int schedule(const vector<int>& day_require, const vector<int>& pay, const int totaldays, int total_pay, int startday)
{
	int ret = 0;
	int workday = -1;
	int i;
	for (i = startday; i < totaldays; ++i)
	{
		if (!work[i] && (day_require[i] + i <= totaldays)) {	//<=를 한 이유는 1일은 당일에 가능하기 때문
			workday = i;
			break;
		}
	}
	if (workday == -1) return total_pay;
	memset(work + workday, true, day_require[workday]);
	total_pay += pay[workday];
	for (i = workday + day_require[workday]; i <= totaldays; ++i) { //<=를 한 이유는 1일은 당일에 가능하기 때문
		int cand = schedule(day_require, pay, totaldays, total_pay, i);
		ret = max(cand, ret);
	}
	memset(work + workday, false, day_require[workday]);
	return ret;
}

int main()
{
	int n;
	cin >> n;
	vector<int> pay;
	vector<int> require_day;
	for (int i = 0; i < n; ++i)
	{
		int _pay;
		int _require_day;
		cin >> _require_day >> _pay;
		pay.push_back(_pay);
		require_day.push_back(_require_day);
	}


	int max_pay = 0;
	for (int i = 0; i < n; ++i)
	{
		max_pay = max(max_pay, schedule(require_day, pay, n, 0, i));
	}
	cout << max_pay;
}