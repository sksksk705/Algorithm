//2022_04_06 랜덤문제풀이
//24394번 123456789점

//아이디어: 굿노트 1개당 최소 점수는 2만 5천 & 굿노트 1개의 점수 이하는 prefect의 갯수
#include <bits/stdc++.h>

using namespace std;

const double MAX = 1000000000.0;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, S;
		cin >> N >> S;
		//1. Good 노트의 개당 점수를 구한다.
		//2. good의 개수: S / good 당 점수.
		//3. perfect의 개수: S - (good의 개수 * good 당 점수)
		//(최대 20000개의 노트라 해도 굿당 최소값은 25000 a는 20000이하 이기 때문에 알아낼 수 있다).
		//4. perfect*2가 good의 개수보다 많거나 perfect가 N의 개수보다 적으면 -1
		double pointPerGood = MAX /(2*N);
		int needGood = S / pointPerGood;
		double perfect = S - needGood * pointPerGood;
		if (perfect*2 > needGood || perfect > N)
			cout << -1;
		else
			cout << needGood << " " << round(perfect);
		cout << '\n';
	}
}