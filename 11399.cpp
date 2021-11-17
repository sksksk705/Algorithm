#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    
    cin >> N;
    vector<int> line;

    for (int i = 0; i < N; ++i) {
        cin >> P;
        line.push_back(P);
    }

    sort(line.begin(), line.end());
    
    int ans = 0;
    for (auto p : line)
        ans += p * N--;

    cout << ans;

}