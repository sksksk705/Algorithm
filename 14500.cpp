#include <iostream>

using namespace std;

//5 乞丞
//4 噺穿
//4 牒
//2 x,y
int poly[7][4][4][2]{
	{	//けけけけ
		{{0,0},{1,0},{2,0},{3,0}},
		{{0,0},{0,1},{0,2},{0,3}},
		{{0,0},{1,0},{2,0},{3,0}},
		{{0,0},{0,1},{0,2},{0,3}}
	},
	{	//けけ
		//けけ
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}}
	},

	{	//けけけ
		//け
		{{0,0},{0,1},{1,0},{2,0}},
		{{0,0},{1,0},{1,1},{1,2}},
		{{0,0},{1,0},{2,0},{2,-1}},
		{{0,0},{0,1},{0,2},{1,2}}

	},
	{	//けけけ
		//    け
		{{0,0},{1,0},{2,0},{2,1}},
		{{0,0},{1,0},{1,-1},{1,-2}},
		{{0,0},{0,1},{1,1},{2,1}},
		{{0,0},{1,0},{0,1},{0,2}}

	},
	{	//けけ
		//  けけ
		{{0,0},{1,0},{1,1},{2,1}},
		{{0,0},{1,0},{1,-1},{0,1}},
		{{0,0},{1,0},{1,1},{2,1}},
		{{0,0},{1,0},{1,-1},{0,1}}

	},
	{	//  けけ
		//けけ
		{{0,0},{1,0},{0,1},{-1,1}},
		{{0,0},{1,0},{0,-1},{1,1}},
		{{0,0},{1,0},{0,1},{-1,1}},
		{{0,0},{1,0},{0,-1},{1,1}}
	},
	{	//  け
		//けけけ
		{{0,0},{1,0},{2,0},{1,-1}},
		{{0,0},{0,1},{0,2},{1,1}},
		{{0,0},{1,0},{2,0},{1,1}},
		{{0,0},{0,1},{0,2},{-1,1}}
	}
};

int board[501][501];

bool inRange(int x, int y, int w, int h) {
	if (x < 0 || x >= w ||
		y < 0 || y >= h)
		return false;
	return true;
}

int getValue(int x, int y, int block, int rotation, int w, int h) {
	int result = 0;
	for (int i = 0; i < 4; ++i) {
		int blockx = x + poly[block][rotation][i][0];
		int blocky = y + poly[block][rotation][i][1];
		if (!inRange(blockx, blocky, w, h))
			return -1;
		else
			result += board[blocky][blockx];
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int ans = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int block = 0; block < 7; ++block)
				for (int rotation = 0; rotation < 4; ++rotation)
					ans = max(ans, getValue(j, i, block, rotation, m, n));

	cout << ans;
}