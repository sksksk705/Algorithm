//2022_04_19 �κ���
//3020�� ���˹���

//N�� 20��, H�� 50�� �޸𸮰� ����
//��ȭ�� ret[h][i%2] = ret[h][(i+1)%2] + ���� �Ͱ� �ε����°�?;
//�ð����⵵: O(NH): 1000���?
//�ð��� ��� �ٿ����ұ�?
//�ؿ������� ���� �ڽź��� ���� ������ �μ� �� ���� �ν����ϰ�
//���������� ���� �ڽź��� ���� ������ �μ� �� ���� �ν����� -> ������
//�ð����⵵: O(n + h)
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