#include <bits/stdc++.h>

using namespace std;

vector<int> table;
int n, d, k, c;
int haveEat[3001];

int eatAMAP() {
	int i = 0;
	int j = 0;
	int eat = 0;
	int ans = 0;
	int cInMax = false;
	for (; j < k;++j) {
		if (!haveEat[table[j % n]]++) {
			eat++;
		}
	}
	if (haveEat[c])
		cInMax = true;
	ans = eat;
	if (!cInMax)
		ans++;
 	while (i < n) {
		if (--haveEat[table[i]] == 0)
			eat--;
		if (++haveEat[table[j % n]]  == 1)
			eat++;
		if (haveEat[c])
			cInMax = true;
		else
			cInMax = false;
		if (eat >= ans) {
			ans = eat;
			if (!cInMax)
				ans++;
		}
		i++; j++;
	}
	return ans;
}

int main() {


	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i) {
		int sushi;
		cin >> sushi;
		table.push_back(sushi);
	}
	cout<<eatAMAP();
}