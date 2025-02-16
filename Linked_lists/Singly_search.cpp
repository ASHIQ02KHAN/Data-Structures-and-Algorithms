#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at the end (for easier testing)
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

// Function to search for a value in the list
int search(Node* head, int value) {
    Node* curr = head;
    int position = 1;

    while (curr != nullptr) {
        if (curr->data == value) {
            return position;
        }
        curr = curr->next;
        position++;
    }

    // If the value is not found
    return -1;
}

// Function to display the list
void traverseList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert some nodes
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    cout << "Initial list: ";
    traverseList(head);

    // Search for a value
    int value = 30;
    int position = search(head, value);
    if (position != -1) {
        cout << "Value " << value << " found at position " << position << "." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Search for another value
    value = 60;
    position = search(head, value);
    if (position != -1) {
        cout << "Value " << value << " found at position " << position << "." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    return 0;
}
