//2022_04_06 랜덤문제풀이
//14719번 빗물

//pop한 블럭만큼 현재 높이의 블럭을 넣어주기(물이 찼다)
#include <bits/stdc++.h>

using namespace std;

int world[500];
int waterWidth[500];
int main() {
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < W; ++i) {
		cin >> world[i];
	} 
	vector<int> blocks;
	int total = 0;
	for (int i = 0; i < W; ++i) {
		int pop_num = 1;
		while (!blocks.empty() && world[i] > blocks.back()) {
			int height = min(world[i], blocks.front());
			total += (height - blocks.back());
			blocks.pop_back();
			pop_num++;
		}
		while (pop_num) {
			blocks.push_back(world[i]);
			pop_num--;
		}
	}
	cout << total;
}