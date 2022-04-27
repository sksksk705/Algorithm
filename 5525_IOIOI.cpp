//2022_04_25 문자열
//5525번 IOIOI

//IOI만 찾아서 연결되있는 개수가 N개 이상이면 정답에 그 길이로 만들 수 있는 결과 더해주기.

#include <bits/stdc++.h>

using namespace std;

const string target = "IOI";

int main() {
	int n, s;
	string str;
	cin >> n >> s >> str;

	vector<bool> ret(s,false);
	for (int i = 0; i < s-2; ++i) {
		//해당 위치에서 IOI를 만들 수 있다면 true;
		if (str[i] == 'I')
		{
			bool match = true;
			for (int j = 0; j < 3; ++j)
			{
				if (str[i + j] != target[j])
				{
					match = false;
					break;
				}
			}
			if (match)
				ret[i] = true;
		}
	}

	//ioiLen: 연결되어있는 IOI개수
	//total: 결과
	int ioiLen = 0;
	int total = 0;
	for (int i = 0; i < ret.size();i++) { 
		if (ret[i] == true) {
			ioiLen = 1;
			while (ret[i + 2] == true) {
				i += 2;
				ioiLen++;
			}
			//IOI가 n개 이상 연결되어 있을 때 ioiLen - n + 1개만큼 만들 수 있다.
			if(ioiLen >= n)
				total += ioiLen - n + 1;
		}
	}

	cout << total;
}