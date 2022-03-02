#include <iostream>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> yin;
priority_queue<int> yang;
int zero = 0;
int result = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num > 1)
            yang.emplace(num);
        else if (num < 0)
            yin.emplace(num);
        else if (num == 0)
            zero++;
        else
            result += 1;
    }
    while (yin.size() >= 2) {
        int smallest = yin.top(); yin.pop();
        int next = yin.top(); yin.pop();
        result += smallest * next;
    }
    while (yang.size() >= 2) {
        int biggest = yang.top(); yang.pop();
        int next = yang.top(); yang.pop();
        result += biggest * next;
    }
    if (!yin.empty()) {
        result += yin.top() * (zero == 0);
    }
    if (!yang.empty()) {
        result += yang.top();
    }
    cout << result;
    return 0;
}