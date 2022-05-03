//2022_05_03 ��������Ǯ��
//9007�� ī������

//��Ž:O(n^4)
//k�� 40000000�̱� ������ dp�� ������ �ٿ��� ��
//�̺� Ž���� 4�� Ȱ���غ���

//������ �ߴµ� ��������� ū ���� ������ �׺��� ���� ���� ��Ī���� �ʴ� �������� �߻� 
//������ �ݴ�� �ϸ� �׺��� ū ���� �� �̻� ã�ƺ��� ���Ѵ�. �� 1���� 1���� ����� ���� ���� �̻����� ���� ��ǥ������ ũ�ٸ� �� �̻� ��Ī���� �ʴ´�...
//2���϶� hi�� 0���� -1���� 2���� ���� ���ε� ��Ī�غ��� ������ �� �ȴ�... ���� ������ ����ϳ�...?
//�˻��غ��� �׳� �� 2�� �Ʒ� 2���� �� ���� �迭�� ���� �ߴ�.
#include <bits/stdc++.h>

using namespace std;

void input(vector<vector<int>>& students, int n) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			int weight;
			cin >> weight;
			students[i].push_back(weight);
		}
	}

	for (int i = 0; i < 4; ++i)
		sort(students[i].begin(), students[i].end());
}


int KanuPlayer(vector<vector<int>> students, int classroom, int totalWeight, int stuNum) {
	if (classroom > 3)
		return 0;
	int hi = stuNum-1;
	int lo = 0;
	int bestdiff = 987654321;
	int bestWeight = 987654321;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int stuWeight = students[classroom][mid];
		int teamWeight = stuWeight + KanuPlayer(students, classroom + 1, totalWeight - stuWeight, stuNum);
		if (teamWeight< totalWeight || stuNum == 2) {
			lo = mid+1;
		}
		else
			hi = mid-1;

		int nowdiff = abs(totalWeight - teamWeight);
		if (nowdiff <= bestdiff) {
			if (nowdiff < bestdiff)
				bestWeight = teamWeight;
			else
				bestWeight = min(bestWeight, teamWeight);
			bestdiff = nowdiff;
		}
	}
	return bestWeight;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int k, n;
		cin >> k >> n;
		vector<vector<int>> students(4);
		input(students,n);
		int result = KanuPlayer(students, 0, k, n);
		cout << result<<'\n';
	}

}