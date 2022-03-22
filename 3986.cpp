//2022_03_22 랜덤문제풀이
//3986 좋은단어

//아이디어: 스택에 담다가 size가 2가 넘었는데 top이 다음 글자와 다르면 x, 끝까지 가서 pop가능하면 0
//실수1: 순서대로 나오는 것만 고려함, BABBAB 같이 순서가 지켜지지 않아도 괜찮음. 
//-정답
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 0;
	while (n--) {
		stack<int> s;
		string str;
		cin >> str;
		for (auto c : str) {
			//에러방지
			if (!s.empty()) {
				//순서대로 나왔을 때
				if (s.top() == c)
					s.pop();
				else
					//겹치지 않는 것이 나왔을 때
					s.push(c);
			}
			else
				//비어있다면
				s.push(c);
		}
		if (s.empty())
			result++;
	}
	cout << result;
}