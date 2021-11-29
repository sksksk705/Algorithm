#include <iostream>
#include <string>

using namespace std;

struct Queue {
    int queue[10001]{ 0 };
    int idx = 0;
    int start = 0;

    void push(int x) {
        queue[idx] = x;
        ++idx;
    }

    void pop() {
        if (idx == start)
            cout << "-1\n";
        else
            cout << queue[start++] << '\n';
    }

    void size() {
        cout << idx - start << '\n';
    }

    void empty() {
        if (idx == start)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    void front() {
        if (start == idx)
            cout << "-1\n";
        else
            cout << queue[start] << '\n';
    }

    void back() {
        if (start == idx)
            cout << "-1\n";
        else
            cout << queue[idx-1] << '\n';
    }
};


int main() {
    string op;
    int num;
    int n;

    Queue q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "push") {
            cin >> num;
            q.push(num);
            continue;
        }
        if (op == "front") {
            q.front();
            continue;
        }
        if (op == "back") {
            q.back();
            continue;
        }
        if (op == "pop") {
            q.pop();
            continue;
        }
        if (op == "size") {
            q.size();
            continue;
        }
        if (op == "empty") {
            q.empty();
            continue;
        }
    }
}