#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert in beginning >>>
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;

    return head;
}

// Function to insert at the end >>>
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

// Function to insert at a specified position >>
Node* insertAtPosition(Node* head, int pos, int value) {
    if (pos < 1) {
        cout << "sorry invalid position!" << endl;
        return head;
    }

    if (pos == 1) {
        return insertAtBeginning(head, value);
    }

    Node* curr = head;
    int count = 1;
    while (count < pos - 1 && curr != nullptr) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Sorry invalid position" << endl;
        return head;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;

    return head;
}

// Function delete from  beginning >>>
Node* deleteFromBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is already empty " << endl;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}

// Function to delete from the end >>>>
Node* deleteFromEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is already empty" << endl;
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;

    return head;
}

// Function to delete from a given position >>>>
Node* deleteFromPosition(Node* head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "sorry Invalid position or it is a empty list nothing to delete " << endl;
        return head;
    }

    if (pos == 1) {
        return deleteFromBeginning(head);
    }

    Node* curr = head;
    int count = 1;
    while (count < pos && curr != nullptr) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Position out of range!" << endl;
        return head;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }

    delete curr;
    return head;
}

// Function to display the list >>
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

    // At the beginning >>>
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    cout << "List after inserting at the beginning: ";
    traverseList(head);

    // At the end >>>>
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    cout << "List after inserting at the end: ";
    traverseList(head);

    // At a specific position >>>>
    head = insertAtPosition(head, 3, 25);
    cout << "List after inserting at position 3: ";
    traverseList(head);

    // Delete from the beginning >>>>
    head = deleteFromBeginning(head);
    cout << "\n\nList after deleting from the beginning: ";
    traverseList(head);

    // Delete from the end >>>>
    head = deleteFromEnd(head);
    cout << "List after deleting from the end: ";
    traverseList(head);

    // Delete from a specific position >>>
    head = deleteFromPosition(head, 2);
    cout << "List after deleting from position 2: ";
    traverseList(head);

    return 0;
}
