//2022_03_29 ��������Ǯ��
//14658 �ϴÿ��� ���˺��� ����ģ��.

//18:40�� ���� 19:17�� ����
//19:47�� ���� 20:02�� �޽�
//���̵��: ���˺� 1���� �������� �ִ� ��� ���˺��� �޾� �� �� �ִ��� ��� 
//��Ž���� ����ϱ� �ð��� �ʹ� �����ɸ� - ���� ���� ������ �ش� ���� idx�� �ٲ�(dp�� ��������)
//���� ���� idx�� ���� �� �̶����� right_bottom�� ������ ���� ����(�߰��ϸ� dp�Ұ���)
//20:43����

#include <bits/stdc++.h>

using namespace std;

int N, M, L, K;
const int INF = 987654321;
pair<int,int> star[100];
int cache[101][101][101];
int solution(int idx, int left_star, int top_star) {
	int& ret = cache[idx+1][left_star+1][top_star+1];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = idx + 1; i < K; ++i) {
		if (idx == -1) {
			ret = max(ret, solution(i, i, i) + 1);
			continue;
		}
		if (star[i].first - star[left_star].first >= L ||
			star[i].second - star[top_star].second >= L)
			continue;
		int next_left = star[left_star].first > star[i].first ? i : left_star;
		int next_top = star[top_star].second > star[i].second ? i : top_star;
		ret = max(ret, solution(i, next_left, next_top)+1);
	}
	return ret;
}

using namespace std;

int main() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		star[i] = make_pair(x, y);
	}
	memset(cache, -1, sizeof(cache));
	cout << K - solution(-1, -1, -1);
}