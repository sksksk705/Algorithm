//2022_05_09 �÷�Ƽ�� ����
//11438�� LCA2

//Ʈ���� �־����� ������ ����Ŭ�� �߻����� �ʴ´�.
//������ �ִ� ��忡 ���� ��带 �ڽ����� �д�.

#include <bits/stdc++.h>

using namespace std;

int tree[100001];

int main() {
	tree[1] = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		if (tree[node1] != 0)
			tree[node2] = node1;
		else
			tree[node1] = node2;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		vector<bool> parent(n+1,0);
		
		//1���� ���ư��鼭 Ʈ���� Ÿ�� �ö󰣴�. ����� ���� ������ break;
		while (true) {
			if (parent[node1]) {
				cout << node1 << '\n';
				break;
			}
			parent[node1] = true;
			node1 = tree[node1];

			if (parent[node2]) {
				cout << node2 << '\n';
				break;
			}
			parent[node2] = true;
			node2 = tree[node2];
		}
	}
}