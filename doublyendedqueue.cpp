#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the deque with given capacity
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the deque is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Insert an element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at front." << endl;
            return;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1; // Circular movement
        } else {
            front--;
        }
        arr[front] = value;
        cout << value << " inserted at the front." << endl;
    }

    // Insert an element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at rear." << endl;
            return;
        }
        if (front == -1) { // If deque is empty
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0; // Circular movement
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " inserted at the rear." << endl;
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from front." << endl;
            return;
        }
        cout << arr[front] << " deleted from the front." << endl;
        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0; // Circular movement
        } else {
            front++;
        }
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from rear." << endl;
            return;
        }
        cout << arr[rear] << " deleted from the rear." << endl;
        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1; // Circular movement
        } else {
            rear--;
        }
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity; // Circular movement
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.display();

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    return 0;
}
