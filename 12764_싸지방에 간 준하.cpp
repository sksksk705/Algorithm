//2022_05_03 ��������Ǯ��
//12764�� �����濡 �� ����

#include <bits/stdc++.h>

using namespace std;

int pc[100001];
bool Using[100001];

int main() {
	int n;
	cin>>n;
	int pcNeed = 1;
	vector<pair<int, int>> people;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> useQ;
	for (int i = 0; i < n; ++i) {
		int p, q;
		cin >> p >> q;
		people.push_back(make_pair(p, q));
	}

	//���� �ð� ������� ����
	sort(people.begin(), people.end());

	for (int person = 0; person < n; ++person) {
		int start, end;
		start = people[person].first;
		end = people[person].second;

		//���� ����� ���۽ð����� �������� �� ���� �� �� ����� ��� �������� �ش� ��ǻ�͸� ��밡���ϰ� ����
		while (!useQ.empty() && useQ.top().first < start) {
			Using[useQ.top().second] = false;
			useQ.pop();
		}

		//�ƹ��� ��ǻ�͸� �ϰ� ���� �ʴٸ� ù��° �ڸ��� ����
		if (useQ.empty()) {
			useQ.push(make_pair(end, 0));
			pc[0]++;
			Using[0] = true;
		}
		else{
			//��� pc�� �̿����̶�� pc�� �ϳ� �� �����ؼ� ����
			if (useQ.size() == pcNeed) {
				useQ.push(make_pair(end, pcNeed));
				Using[pcNeed] = true;
				pc[pcNeed]++;
				pcNeed++;
			}
			else {
				//����ִ� pc�ڸ� �� ���� �տ� �ִ� �ڸ��� ����
				for (int i = 0; i < pcNeed; ++i)
				{
					if (!Using[i]) {
						useQ.push(make_pair(end, i));
						Using[i] = true;
						pc[i]++;
						break;
					}
				}
			}
		}
	}
	
	cout << pcNeed<<'\n';
	for (int i = 0; i < pcNeed; ++i)
		cout << pc[i] << " ";
}
