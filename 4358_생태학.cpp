//2022_04_25 ���ڿ�
//4358_������

//�ؽø� �Ἥ �ϳ��� �����ְ� ��ü ������ �ش� Ű���� �����ָ� �ɵ�
//������ �ؼ� �⿪�ؾ� �ؼ� �ٷ� ���� ���� �� ������.
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