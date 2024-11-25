#include <iostream>
using namespace std;

class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;  // Pointer to the first node

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
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
            newNode->prev = temp;
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
            if (head != nullptr) {
                head->prev = newNode;
            }
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
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
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
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            cout << value << " deleted from the list." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << value << " not found in the list." << endl;
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            delete temp;
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

    // Display the linked list (Forward direction)
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List (Forward): ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display the linked list (Backward direction)
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Linked List (Backward): ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Reverse the linked list
    void reverse() {
        if (head == nullptr) {
            cout << "List is empty. Cannot reverse." << endl;
            return;
        }

        Node* temp = nullptr;
        Node* current = head;

        // Swap next and prev pointers
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Reset head to the new first node
        if (temp != nullptr) {
            head = temp->prev;
        }
        cout << "Linked list reversed." << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);

    list.displayForward();
    list.displayBackward();

    list.deleteByValue(20);
    list.displayForward();

    cout << "Is 15 in the list? " << (list.search(15) ? "Yes" : "No") << endl;

    list.reverse();
    list.displayForward();
    list.displayBackward();

    return 0;
}
