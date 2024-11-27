#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    Queue(int size) {
        front = rear = -1;
        capacity = size;
        queue = new int[size];
    }

    void Enqueue(int object) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (IsEmpty())
            front = 0;
        rear++;
        queue[rear] = object;
        cout << object << " enqueued successfully." << endl;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int object = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        cout << object << " dequeued successfully." << endl;
        return object;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return queue[front];
    }

    void ReverseQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot reverse." << endl;
            return;
        }
        int* temp = new int[capacity];
        int index = 0;
        for (int i = rear; i >= front; i--) {
            temp[index] = queue[i];
            index++;
        }
        delete[] queue;
        queue = temp;
        cout << "Queue reversed successfully." << endl;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return rear == capacity - 1;
    }
};

int main() {
    Queue queue(5);

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    queue.Dequeue();
    queue.Dequeue();

    cout << "Front element: " << queue.Peek() << endl;

    queue.ReverseQueue();

    return 0;
}