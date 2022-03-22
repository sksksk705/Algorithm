//2022_03_22 ��������Ǯ��
//5052 ��ȭ��ȣ ���

//���̵��1: 
//���̸� �������� sort�ϰ� ����set�� ����
//��Ʈ�� vec�� idx���� ���� ���̸�ŭ for������ ã��
//���ٸ� �ؽ��ʿ� �ش� �� �߰�. �ѹ��� ������ set�����
//���� ���̰� ���ٸ� ������ �ʾƵ� ��.

//�ִ� 500������ �������� ó������
//-����

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool cmp(const string& s1,const  string& s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	return s1.size() < s2.size();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		unordered_set<string> hash;
		int n;
		cin >> n;
		set<int> numlength;
		vector<string> nums(n);
		for (int i = 0; i < n; ++i) {
			string num;
			cin >> num;
			nums[i] = num;
		}
		//����, ���� ������� ����
		sort(nums.begin(), nums.end(), cmp);

		//����set ����
		for (auto num : nums)
			numlength.insert(num.size());

		bool isConsistent = true;
		for (int i = 0; i < n; ++i) {
			int nowLength = nums[i].size();
			for (auto length : numlength) {
				//������̰� ���λ��� ���̿� ���ٸ� �� X (���� ���ڴ� �������� ����)
				if (nowLength <= length)
					continue;

				//���λ簡 ���� �����߾����� Ž��
				string head = nums[i].substr(0, length);

				//�����ߴٸ� �ϰ������� �ʴ�.
				if (hash.find(head) != hash.end()) {
					isConsistent = false;
					break;
				}
			}
			if (!isConsistent)
				break;
			//Ž������ �� �ؽÿ� ���� �� �߰�
			hash.insert(nums[i]);
		}
		if (isConsistent)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}