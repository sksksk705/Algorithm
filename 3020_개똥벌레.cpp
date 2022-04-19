//2022_04_19 부분합
//3020번 개똥벌레

//N이 20만, H가 50만 메모리가 부족
//점화식 ret[h][i%2] = ret[h][(i+1)%2] + 지금 것과 부딪히는가?;
//시간복잡도: O(NH): 1000억번?
//시간을 어떻게 줄여야할까?
//밑에서부터 새면 자신보다 높은 구간이 부순 건 전부 부숴야하고
//위에서부터 새면 자신보다 낮은 구간이 부순 건 전부 부숴야함 -> 누적합
//시간복잡도: O(n + h)
#include <bits/stdc++.h>

using namespace std;
int retbottom[500001];
int rettop[500001];
int obstacle[500001][2];
int psum[200001];

int main() {
	int n, h;
	cin >> n >> h;
	
	for (int i = 0; i < n; ++i)
	{
		int ob;
		cin >> ob;
		obstacle[ob-1][i%2]++;
	}

	for (int height = h-1; height >= 0; --height)
	{
		retbottom[height] = retbottom[height + 1];
		if (obstacle[height][0] > 0)
			retbottom[height] += obstacle[height][0];
	}

	for (int height = h-1; height >= 0; --height)
	{
		rettop[height] = rettop[height + 1];
		if (obstacle[height][1] > 0)
			rettop[height] += obstacle[height][1];
	}

	int minToBreak = 200001;
	for (int i = 0; i < h; ++i)
	{
		int needToBreak = retbottom[i] + rettop[h-i-1];
		minToBreak = min(minToBreak, needToBreak);
		psum[needToBreak]++;
	}
	cout << minToBreak << " " << psum[minToBreak];
}