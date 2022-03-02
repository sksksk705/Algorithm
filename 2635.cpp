#include <iostream>
#include <vector>

using namespace std;
vector<int> temp;
vector<int> last;
void brute(int now, int prev, int num) {
    if (now < 0) {
        if (temp.size() > last.size()) {
            last = temp;
        }
        return;
    }
    temp.push_back(now);
    brute(prev - now, now, num + 1);
    temp.pop_back();
}

int main() {
    int n;
    cin >> n;
    temp.push_back(n);
    for (int i = 1; i <= n; ++i) {
        temp.push_back(i);
        brute(n - i,i, 0);
        temp.pop_back();
    }
    cout << last.size()<<'\n';
    for (auto s : last)
        cout << s << ' ';
}