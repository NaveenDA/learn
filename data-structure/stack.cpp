#include <iostream>
using namespace std;
#define capacity 10

class Stack {
public:
    int top;
    int A[capacity];
    Stack();
    void push(int a);
    int pop();
    bool isEmpty();
    bool isFull();
};

Stack::Stack() {
    top = 0;
}

bool Stack::isEmpty() {
    return top == 0;
}

bool Stack::isFull() {
    return top == capacity;
}

void Stack::push(int a) {
    if (!isFull()) {
        A[top] = a;
        top++;
    } else {
        std::cout << "stack overflow\n";
    }
}

int Stack::pop() {
    if (!isEmpty()) {
        top--;
        std::cout << A[top] << " Popped\n";
        return A[top];
    } else {
        std::cout << "stack underflow\n";
        return -9999;
    }
}

int main() {
    Stack stack;

    for (int i = 0; i < 6; i++) {
        // print 0 1 2 3 4 5
        std::cout << i << '\n';
        stack.push(i);
    }

    for (int j = 0; j < 6; j++) {
        stack.pop();
    }

    return 0;
}

