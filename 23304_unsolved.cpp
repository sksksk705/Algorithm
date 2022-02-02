#include <bits/stdc++.h>
#include <string>


using namespace std;

bool check_pal(string s,int depth, bool isodd) {
	depth++;
	if (s.size() == 1) //길이가 1이면 팰린드롬이다.
		return true;
	if (depth == 3) //2번만 실행하면 되기 때문에 깊이가 3이면 통과다.
		return true;

	int size = s.size() / 2;

	if (isodd) {
		for (int i = 1; i <= size; ++i) {
			if (s[size - i] == s[size + i]) //팰린드롬 체크
				continue;
			return false;
		}
		if (check_pal(s.substr(0, size), depth, size % 2) && 
			check_pal(s.substr(size+1, s.size()), depth, size % 2)) //접두사 접미사 팰린드롬 체크
			return true;
	}
	else {
		int left = size - 1;
		int right = size;
		for (int i = 0; i < size; ++i) {
			if (s[left-i] == s[right+i]) //팰린드롬 체크
				continue;
			return false;
		}
		if (check_pal(s.substr(0,size), depth, size % 2) && check_pal(s.substr(right, s.size()), depth, size % 2)) //접두사 접미사 팰린드롬 체크
			return true;
	}

	return false; //통과 못하면 팰린드롬이 아님.
}

int main() {
	string s;
	cin >> s;

	if (check_pal(s, 0, s.size() % 2))
		cout << "AKARAKA";
	else
		cout << "IPSELENTI";
}