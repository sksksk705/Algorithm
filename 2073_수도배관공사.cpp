//2022_04_13 ��������Ǯ��
//2073 ����������� 18:56�� ����

//�ð� 2��, �޸� 128mb -> �׸��� x
//�Է� 10��, 350�� -> dp �Ұ���
//��ǥ: �������� �ִ�뷮 -> ����ȭ
//�ϴ� ����Ž���� �����غ����� ��.

//19:48�� ����
#include <bits/stdc++.h>

using namespace std;

int dist, pipe; //�Ÿ�, ������ ��
int lengthSum[351];
int best = 0;
vector<pair<int, int>> pipes;

//����ġ��� �Լ�
bool simpleHeuristic(int remain, int idx)
{
	//���� �������� ���� �ᵵ �Ÿ��� �� �Ǵ� ���.
	return remain - lengthSum[idx] > 0;
}

//����Ž�� �����Ϸ�, ����� �� 2�� 350�� - ����ȭ �ʿ�
//����ġ�� �����Ϸ�
//idx: ���� ������
//remain: ���� �Ÿ�
//currentCap: ���� �뷮
void solve(int idx, int remain, int currentCap)
{
	//����ġ��
	if (currentCap <= best || simpleHeuristic(remain, idx))
		return;

	//�������1:�������� ���̰� ��ų� ��� �������� Ž���� ���
	if (idx > pipe || remain < 0)
		return;

	//�������2: ��Ȯ�� ������ �������� ���� ���
	if (remain == 0) {
		best = max(currentCap, best);
		return;
	}

	//�ش� �������� ����ϰų� ������� �ʰų�
	solve(idx + 1, remain - pipes[idx].first, min(currentCap, pipes[idx].second));
	solve(idx + 1, remain, currentCap);
}


int main() {
	cin >> dist >> pipe;
	for (int i = 0; i < pipe; ++i)
	{
		int length, capacity;
		cin >> length >> capacity;
		pipes.push_back(make_pair(length, capacity));
	}
	sort(pipes.begin(), pipes.end());

	//i���� ������ ������������ ��
	lengthSum[pipe - 1] = pipes[pipe - 1].first;
	for (int i = pipe - 2; i >= 0; --i)
		lengthSum[i] = lengthSum[i + 1] + pipes[pipe - 1].first;

	solve(0, dist, INT_MAX);
	cout << best;
}