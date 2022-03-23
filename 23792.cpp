//2022_03_23 ���� ���� Ǯ��
//23792�� k��° ����ã��

//21:35�� ����
//Ʈ���� �����ͷ� 3���� ���ϸ鼭 �ϳ��� �ű�� ���� ������?
//�񱳰� �ʹ� ���� �Ǽ� ���� �ϳ��� ���ļ� sort�� �� �ʰ��� ������ ������ �׳� continue�ϴ� �ɷ�
//22:18�� �ð��ʰ� ���̵��: ���� �迭�� 300000 �������� 3���� 
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> foods;
vector<int> idx;


void kndDelicous(int ko, int usa, int jp,int k)
{
	int foodlimit[3]{ ko,usa,jp };
	int foodpasses[3]{ 0,0,0 };
	int idx = 0, total = 0;
	int nowFood;
	//�� k���� ������ ã�ƺ��� �̹� �ʰ��� ���������� total�� �������� �ʴ´�.
	//������ ������ ������ ����Ͽ� �ش� ������ ��� �����ƴ��� ���
	while (total < k) {
		nowFood = foods[idx++].second;
		if (foodpasses[nowFood] >= foodlimit[nowFood]) {
			continue;
		}
		foodpasses[nowFood]++;
		total++;
	}
	cout << foods[idx-1].second + 1 << ' ' << foodpasses[nowFood]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j){
			int food;
			cin >> food;
			foods.push_back(make_pair(food,i));
		}

	sort(foods.begin(), foods.end());
	int Q;
	cin >> Q;
	while (Q--)
	{
		int x, y, z, k;
		cin >> x >> y >> z >> k;
		kndDelicous(x, y, z, k);
	}
}