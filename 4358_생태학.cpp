//2022_04_25 문자열
//4358_생태학

//해시맵 써서 하나씩 더해주고 전체 수에서 해당 키값을 나눠주면 될듯
//정렬을 해서 출역해야 해서 바로 맵을 쓰는 게 나을듯.
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int total = 0;
	string spice = "";
	map<string,int> bio;
	getline(cin, spice);
	while (spice != "")
	{
		bio[spice]++;
		total++;
		getline(cin, spice);
	}

	for (auto tree : bio) {
		cout<<setprecision(4);
		cout << fixed << tree.first << " " << (double)tree.second / total * 100 << "\n";
	}
	return 0;
}