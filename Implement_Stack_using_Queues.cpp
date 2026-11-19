
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
    }

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int result = q1.front();
        q1.pop();
        return result;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);

    cout << "Top: " << myStack.top() << endl;

    cout << "Pop: " << myStack.pop() << endl;

    cout << "Empty: " << (myStack.empty() ? "true" : "false") << endl;

    return 0;
}
