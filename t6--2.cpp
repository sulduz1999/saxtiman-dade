#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void Push(int item) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = item;
    }

    int Pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int Peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool IsEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "Top element: " << stack.Peek() << endl;

    cout << "Popped element: " << stack.Pop() << endl;
    cout << "Popped element: " << stack.Pop() << endl;

    cout << "Is stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}
