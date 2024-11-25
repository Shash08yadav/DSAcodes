#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head; // Pointer to the first node

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning." << endl;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted at the end." << endl;
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << value << " inserted at position " << position << "." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted at position " << position << "." << endl;
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << value << "." << endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found in the list." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << value << " deleted from the list." << endl;
        }
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked list reversed." << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);

    list.display();

    list.deleteByValue(20);
    list.display();

    cout << "Is 15 in the list? " << (list.search(15) ? "Yes" : "No") << endl;

    list.reverse();
    list.display();

    return 0;
}
