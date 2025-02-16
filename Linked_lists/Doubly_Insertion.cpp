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
        cout << "Invalid position!" << endl;
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
        cout << "Invalid position!" << endl;
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

// Function to display list
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

    // At the beginning >>>>
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);
    head = insertAtBeginning(head, 50);


    cout << "After inserting at the beginning the list is : ";
    traverseList(head);

    // At the end >>>
    head = insertAtEnd(head, 60);
    head = insertAtEnd(head, 70);
    head = insertAtEnd(head, 80);
    head = insertAtEnd(head, 90);

    cout << "After inserting at the end the list is: ";
    traverseList(head);

   // At a specific position >>>
    int pos = 2;
    int value = 45;
    head = insertAtPosition(head, pos, value);
    cout << "\nInserting value " << value << " at position " << pos << " : " << endl;
    traverseList(head);
    return 0;
}
