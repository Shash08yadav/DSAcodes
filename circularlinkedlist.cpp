#include <iostream>
using namespace std;

class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;  // Pointer to the first node

public:
    // Constructor to initialize an empty list
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {  // If list is empty
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;  // Last node points to new node
            newNode->next = head;  // New node points to head
            head = newNode;        // Update head to new node
        }
        cout << value << " inserted at the beginning." << endl;
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {  // If list is empty
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;  // Last node points to new node
            newNode->next = head;  // New node points to head
        }
        cout << value << " inserted at the end." << endl;
    }

    // Delete a node from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == head) {  // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;  // Move head to the next node
            temp->next = head;  // Last node points to new head
            delete toDelete;
        }
        cout << "Node deleted from the beginning." << endl;
    }

    // Delete a node from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == head) {  // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {  // Traverse to second last node
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = head;  // Second last node points to head
            delete toDelete;
        }
        cout << "Node deleted from the end." << endl;
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // Loop until we reach the head again
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(30);
    cll.display();

    cll.deleteFromBeginning();
    cll.deleteFromEnd();
    cll.display();

    return 0;
}
