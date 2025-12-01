#include <bits/stdc++.h>
using namespace std;

class Mystack {
private:
    int *arr;
    int capacity;
    int top;

public:
    Mystack(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Mystack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Mystack st;

    vector<string> commands = {"stack", "push", "push","push", "peek", "pop","pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {4}, {10},{15}, {},{}, {}, {}};

    for (size_t i = 0; i < commands.size(); i++) {

        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null" << endl;
        }
        else if (commands[i] == "pop") {
            cout << st.pop() << endl;
        }
        else if (commands[i] == "peek") {
            cout << st.peek() << endl;
        }
        else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << endl;
        }
        else if (commands[i] == "stack") {
            cout << "null" << endl;
        }
    }

    return 0;
}