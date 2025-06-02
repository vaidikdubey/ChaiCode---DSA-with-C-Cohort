#include <iostream>
using namespace std;

class Queue {
    int q[10], front, rear;

    public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if(rear == 9) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1) {
            front++;
            rear++;
            q[front] = value;
        }
        else {
            rear++;
            q[rear] = value;
        }

        cout << "Value " << value << " added to Queue" << endl;
    }

    int dequeue() {
        if(rear == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        if(front == rear) {
            int val = q[front];
            front = -1;
            rear = -1;
            return val;
        }
        else {
            int val = q[front];
            front++;
            return val;
        }
    }

    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    int val = q.dequeue();
    cout << "Dequeue value: " << val << endl;
    val = q.dequeue();
    cout << "Dequeue value: " << val << endl;
    val = q.dequeue();
    cout << "Dequeue value: " << val << endl;
    val = q.dequeue();
    cout << "Dequeue value: " << val << endl;

    if(q.isEmpty()) {
        cout << "Empty Queue" << endl;
    }
    else {
        cout << "Queue has values" << endl;
    }

    return 0;
}