#include <bits/stdc++.h>
using namespace std;
int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    int ret = 1;
    while (true)
    {
        if (E == 1 && S == 1 && M == 1) break;
        if ((ret - E) % 15 == 0 &&
            (ret - S) % 28 == 0 &&
            (ret - M) % 19 == 0) break;
        ++ret;
    }
    cout << ret;
}