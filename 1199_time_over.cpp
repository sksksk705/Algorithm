#include <iostream>
#include <vector>

using namespace std;

int adj[1050][1050];
int V;

void getEulerCircuit(int here)
{
	for(int there = 1; there <=V;++there){
		if (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there);
		}
	}
	cout << here << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V;
	for (int start = 1; start <= V; ++start) {
		int cnt = 0;
		for (int to = 1; to <= V; ++to) {
			int degree;
			cin >> degree;
			adj[start][to] = degree;
			cnt+= degree;
		}
		if (cnt % 2) { cout << -1; return 0; }
	}

	getEulerCircuit(1);
}