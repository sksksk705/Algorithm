#include <bits/stdc++.h>

using namespace std;

int possible[3]{ 0,-1,1 };
const int MAX = 200002;
bool visited[200002];
struct Node {
	Node* parent = nullptr;
	int n;
};

Node* root = new Node;

void bfs(int start, int to) {
	if (start == to) {
		cout << 0 << '\n';
		cout << start;
		return;
	}
	queue<Node*> q;
	queue<int> moveq;
	root->n = start;
	moveq.push(0);
	q.push(root);
	while (!q.empty()) {
		auto now = q.front();
		int move = moveq.front();
		q.pop(); moveq.pop();
		possible[0] = now->n;
		for (int i = 0; i < 3; ++i) {
			int next = now->n + possible[i];
			if (next < 0 || next >= MAX
				||visited[next])
				continue;
			Node* child = new Node;
			child->parent = now;
			child->n = next;
			if (next == to) {
				cout << move + 1<<'\n';
				stack<int> s;
				while (true) {
					s.push(child->n);
					if (child->n == start)
						break;
					child = child->parent;
				}
				while (!s.empty()) {
					cout << s.top()<<' ';
					s.pop();
				}
				return;
			}
			visited[next] = true;
			q.push(child);
			moveq.push(move + 1);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	
}