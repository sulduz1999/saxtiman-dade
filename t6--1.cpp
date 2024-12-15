#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    void Enqueue(int value) {
        stack1.push(value);
    }

    int Dequeue() {
        if (stack1.empty() && stack2.empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }
};

int main() {
    Queue queue;
   
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
   
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
   
    queue.Enqueue(40);
   
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
   
    return 0;
}
