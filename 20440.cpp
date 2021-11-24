#include <bits/stdc++.h>

using namespace std;
int room[2000001]; //100만개의 입출입이 들어오기 때문에 200만개의 타이밍이 가능함
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
	for (int i = 1; i < 2* n; ++i) { //2*n을 변수로 선언해서 Timing으로 했다면 좀 더 코드가 예뻤을듯
		room[i] += room[i-1]; //원래 2중 for문으로 1개씩 더해줬지만 해답보고 누적합으로 해결
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