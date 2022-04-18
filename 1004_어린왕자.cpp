//2022_04_15 계산기하
//1004번 어린왕자

//한 점은 포함하지만 동시에 포함하지 않는 원에 대해 값을 증가시켜야함. XOR
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		double n;
		cin >> n;

		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			bool prince, planet;
			double cx, cy,r;
			cin >> cx>>cy>>r;

			sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r ? prince = true : prince = false;
			sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r ? planet = true : planet = false;

			result += (planet ^ prince);
		}
		cout << result << '\n';
	}

}