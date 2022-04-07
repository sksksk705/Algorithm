//2022_04_07 �׸���
//19621 ȸ�ǽ� ����2

//���� ���� ������ ȸ�Ǹ� ���ϰ� �ش� ȸ�ǿ� ��ġ�� ȸ�ǵ��� ����Ѵ�.
//�ִ� �ο���, n�� 25�̱� ������ dp�� ����ؾ��ҵ�
//dp�� ����ϱ⿡�� �ð��� intMAX�̱� ������ ��Ž���� �ذ�
//16:34 �ð��� �������� �ϴ� �� �ƴ϶� �ﰢ�� �ִ���ó�� �ؾ��ҵ�
#include <bits/stdc++.h>

using namespace std;

int cache[25];
int people[25];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, e;
		cin >> s >> e;
		cin >> people[i];
	}
	int ret = 0;
	ret = max(people[0], people[1]);
	cache[0] = people[0];
	cache[1] = people[1];
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < i-1; ++j) {
			cache[i] = max(cache[i],cache[j] + people[i]);
		}
		ret = max(ret, cache[i]);
	}
	cout << ret;
}