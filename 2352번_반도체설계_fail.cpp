//2022_05_02 ��������Ǯ��
//2352�� �ݵ�ü����

//���� ������ �ִ� ���� ���ϱ� n = 40000;
//ž�ٿ��� �� �Ǵϱ� �Ӹ��� �Ͼ����� ������ �ٽ� �ϴ� �ɷ�
#include <bits/stdc++.h>

using namespace std;

int cache[40002];
int connect[40001];
int n;

//stackoverflow�� �����. �ݺ������� �����Ѱ�?
int topDown(int idx) {
	int& ret = cache[idx+1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = idx + 1; i < n; ++i) {
		if (idx == -1 || connect[idx] < connect[i])
			ret = max(ret, topDown(i) + 1);
	}
	return ret;
}

int bottomUp() {
	int ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		cache[i] = 1;
		for (int j = i+1; j < n; ++j) {
			if (connect[i] < connect[j])
			{
				cache[i] = max(cache[i + 1], cache[j] + 1);
				break;
			}
		}
		cache[i] = max(cache[i], cache[i + 1]);
		ret = max(ret, cache[i]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> connect[i];

	int result = bottomUp();
	cout << result;
}