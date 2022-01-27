#include <bits/stdc++.h>

// 잃어버린 괄호
// 최솟값을 만들고 + - 밖에 없기 때문에 + 밖에 나오지 않았다면 다 더하고
// 한번이라도 - 가 나왔다면 그 뒤에는 전부 뺀다.

using namespace std;

enum STATE {PLUS , MINUS};		//빼기 부호가 나왔었는지 체크하기 위한 상태변수(기본 플러스)

int main()
{
	int result = 0;

	string numstr ("");			//0을 처리하기 위해 문자열로 받아들임.
	char ch;
	int idx = 0;
	STATE state = PLUS;
	while (true)		
	{
		cin.get(ch);			//한 문자씩 체크
		if (isdigit(ch))		//숫자라면 string에 추가
			numstr += ch;
		else					//기호라면 string을 숫자로 바꿔주고 전에 '-'가 있었다면 빼고 '+'밖에 없었다면 더한다.
		{
			int realnum = stoi(numstr);
			if (state == MINUS)
				result -= realnum;
			else if (state == PLUS)
			{
				if (ch == '-') {
					state = MINUS;	//'-'부호가 나오면 상태를 마이너스로 바꿔준다.
				}
				result += realnum;
			}
			numstr = "";	//빈 문자열로 초기화
		}
		if (ch == '\n')
			break;
	}
	cout << result;

	return 0;
}