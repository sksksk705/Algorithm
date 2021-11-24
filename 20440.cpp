#include <bits/stdc++.h>

using namespace std;
int room[2000001]; //100������ �������� ������ ������ 200������ Ÿ�̹��� ������
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> in;
	vector<int> out;
	vector<int> idx;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int tem, txm;
		cin >> tem >> txm;
		in.push_back(tem);
		out.push_back(txm);
		idx.push_back(tem);
		idx.push_back(txm);
	}
	sort(idx.begin(), idx.end());

	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	

	for (int i = 0; i < n; ++i) {
		int in_idx = lower_bound(idx.begin(), idx.end(), in[i]) - idx.begin();
		int out_idx = lower_bound(idx.begin(), idx.end(), out[i]) - idx.begin();
		++room[in_idx]; --room[out_idx];
	}
	for (int i = 1; i < 2* n; ++i) { //2*n�� ������ �����ؼ� Timing���� �ߴٸ� �� �� �ڵ尡 ��������
		room[i] += room[i-1]; //���� 2�� for������ 1���� ���������� �ش亸�� ���������� �ذ�
	}

	int Max = *max_element(room, room + 2*n); 
	int maxidx = 0;
	int maxendidx = 0;
	for (int i = 0; i < n*2; ++i) {
		if (room[i] == Max) {
			maxidx = i;
			for (int j = i; j < n*2; ++j) {
				if (room[j] != Max) {
					maxendidx = j;
					break;
				}
			}
			break;
		}
	}


	cout << Max << '\n' << idx[maxidx] << " " << idx[maxendidx];
}