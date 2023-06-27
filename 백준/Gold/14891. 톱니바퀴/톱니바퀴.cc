#include <bits/stdc++.h>

using namespace std;

struct GEAR {
	string state;
	int right;
	int left;
	GEAR() {}
	GEAR(string s) { 
		state = s;  		
		right = state[2];
		left = state[6];
	}
	void turnleft() {

		int temp = state[0];
		for (int i = 0; i < 7; ++i)
		{
			state[i] = state[i + 1];
		}
		state[7] = temp;
		right = state[2];
		left = state[6];
	}
	void turnright() {

		int temp = state[7];
		for (int i = 7; i > 0; --i)
		{
			state[i] = state[i - 1];
		}
		state[0] = temp;
		right = state[2];
		left = state[6];

	}
};

int main()
{
	GEAR gears[4];
	for (int i = 0; i < 4; ++i) {
		string s;
		cin >> s;
		gears[i] = s;
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int gear_num, dir;
		cin >> gear_num >> dir;
		int gear_idx = gear_num - 1;
		int rotation_dir[4];
		memset(rotation_dir, 0, sizeof(rotation_dir));
		rotation_dir[gear_idx] = dir;

		for (int j = gear_idx; j < 3; ++j)
		{
			if (gears[j].right != gears[j + 1].left && rotation_dir[j] != 0) {
				rotation_dir[j + 1] = -rotation_dir[j];
			}
		}
		for (int j = gear_idx; j > 0; --j)
		{
			if (gears[j].left != gears[j - 1].right && rotation_dir[j] != 0) {
				rotation_dir[j - 1] = -rotation_dir[j];
			}
		}
		for (int j = 0; j < 4; ++j)
		{
			if (rotation_dir[j] == 1)
				gears[j].turnright();
			else if (rotation_dir[j] == -1)
				gears[j].turnleft();
		}
	}
	int result = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (gears[i].state[0] == '1')
			result += pow(2, i);
	}
	cout << result;
}