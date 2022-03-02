#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int alpha[26];

int main()
{
    int N;
    cin >> N;
    for (int word = 0; word < N; ++word)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            alpha[s[i] - 'A'] += pow(10, s.size() - i - 1);
        }
    }
    int num = 9;
    int result = 0;
    while (true) {
        int idx = -1;
        int MAX = -1;
        for (int i = 0; i < 26; ++i) {
            if (alpha[i] > MAX) {
                MAX = alpha[i];
                idx = i;
            }
            
        }
        if (MAX == 0)
            break;
        result += num * alpha[idx];
        num--; alpha[idx] = 0;
    }
    cout << result;
    return 0;
}