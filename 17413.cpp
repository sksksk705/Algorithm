#include <iostream>
#include <stack>

using namespace std;
stack<char> str;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool tag = false;
    char c;
    while (cin.get(c)) {
        if (c == '<') {
            while (!str.empty()) {
                cout << str.top();
                str.pop();
            }
            cout << c;
            tag = true;
        }
        else if (c == '>') {
            cout << c;
            tag = false;
        }
        else if (isspace(c)) {
            while (!str.empty()) {
                cout << str.top();
                str.pop();
            }
            if (c == '\n')
                return 0;
            cout << c;
        }
        else {
            if (tag != true)
                str.push(c);
            else
                cout << c;
        }
    }
}