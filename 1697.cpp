#include <bits/stdc++.h>

using namespace std;


bool visited[100001];
queue<pair<int,int>> q;

bool isVaild(int nextSubin) {
	if (nextSubin < 1 || nextSubin>100000 || visited[nextSubin])
		return false;
	return true;
}

int moveSubin(int n,int k) {
	while (!q.empty()) {
		int subin = q.front().first;
		int depth = q.front().second;
		visited[subin] = true;
		q.pop(); 
		if (subin == k)
			return depth;

		if (isVaild(subin * 2)) {
			q.push(make_pair(subin * 2, depth + 1));
		}

		if (isVaild(subin + 1)) {
			q.push(make_pair(subin + 1, depth + 1));
		}

		if (isVaild(subin - 1)) {
			q.push(make_pair(subin - 1, depth + 1));
		}

		
	}

}
  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k; 

	if (k < n) {
		cout << n - k;
		return 0;
	}
	q.push({ n, 0 });

	cout<<moveSubin(n, k);
}