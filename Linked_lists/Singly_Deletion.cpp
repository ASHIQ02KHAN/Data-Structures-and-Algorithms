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

// Function to delete from the beginning
Node* deleteFromBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is already empty!" << endl;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to delete from the end
Node* deleteFromEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is already empty!" << endl;
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

// Function to delete from a specified position
Node* deleteFromPosition(Node* head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "Invalid position or list is empty!" << endl;
        return head;
    }

    if (pos == 1) {
        return deleteFromBeginning(head);
    }

    Node* curr = head;
    int count = 1;

    while (count < pos - 1 && curr != nullptr) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr || curr->next == nullptr) {
        cout << "Position out of range!" << endl;
        return head;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
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

    // Delete from the beginning
    head = deleteFromBeginning(head);
    cout << "After deleting from the beginning: ";
    traverseList(head);

    // Delete from the end
    head = deleteFromEnd(head);
    cout << "After deleting from the end: ";
    traverseList(head);

    // Delete from position 2
    int pos = 2;
    head = deleteFromPosition(head, pos);
    cout << "After deleting from position " << pos << ": ";
    traverseList(head);

    return 0;
}
