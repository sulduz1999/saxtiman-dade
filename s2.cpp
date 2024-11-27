#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    Queue(int size) {
        capacity = size;
        front = -1;
        rear = -1;
        queue = new int[capacity];
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Unable to enqueue." << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = item;
        cout << item << " enqueued successfully." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to dequeue." << endl;
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        cout << item << " dequeued successfully." << endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to peek." << endl;
            return -1;
        }
        return queue[front];
    }

    void reverseQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to reverse." << endl;
            return;
        }
        int* temp = new int[capacity];
        int index = 0;
        while (!isEmpty()) {
            temp[index++] = dequeue();
        }
        for (int i = index - 1; i >= 0; i--) {
            enqueue(temp[i]);
        }
        cout << "Queue reversed successfully." << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    cout << "Front element: " << q.peek() << endl;

    q.reverseQueue();

    return 0;
}