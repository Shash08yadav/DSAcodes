#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Dynamic array for the queue
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int capacity;  // Maximum capacity of the queue
    int count;     // Current size of the queue

public:
    // Constructor to initialize queue
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        count++;
        cout << value << " enqueued to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        front = (front + 1) % capacity; // Circular increment
        count--;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Get the size of the queue
    int size() {
        return count;
    }
};

int main() {
    Queue q(5); // Queue with a capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Queue size: " << q.size() << endl;

    q.dequeue();
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
