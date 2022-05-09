//2022_05_09 플레티넘 문제
//11438번 LCA2

//트리로 주어지기 때문에 사이클이 발생하지 않는다.
//조상이 있는 노드에 없는 노드를 자식으로 둔다.

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
		
		//1개씩 돌아가면서 트리를 타고 올라간다. 상대의 조상에 닿으면 break;
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