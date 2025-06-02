#include <iostream>
using namespace std;

class Stack {
    int stk[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int val) {
        if(top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        stk[top] = val;
        cout << "Value " << val << " added to stack" << endl;
    }

    int pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int val = stk[top];
        top--;

        return val;
    }

    int peek() {
        if(top == -1) {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return stk[top];
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Stack s;

    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int val = s.pop();
    cout << "Popped value 1: " << val << endl;
    val = s.pop();
    cout << "Popped value 2: " << val << endl;
    val = s.pop();
    cout << "Popped value 3: " << val << endl;

    val = s.peek();
    cout << "Peek value (value at top): " << val << endl;

    if(s.isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack has some value and is not empty" << endl;
    }

    val = s.pop();
    cout << "Popped value 1: " << val << endl;
    val = s.pop();
    cout << "Popped value 2: " << val << endl;
    val = s.pop();
    cout << "Popped value 3: " << val << endl;

    if(s.isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack has some value and is not empty" << endl;
    }

    return 0;
}