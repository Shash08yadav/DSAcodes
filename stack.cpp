#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Dynamic array for stack
    int top;       // Index of the top element
    int capacity;  // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1; // Stack is empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to the stack." << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from the stack." << endl;
    }

    // Peek operation
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s(5); // Stack with a capacity of 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();
    s.pop();

    cout << "Stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.pop();
    s.pop(); // Attempt to pop from an empty stack

    return 0;
}
