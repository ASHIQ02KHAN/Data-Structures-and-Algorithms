#include <iostream>
#define MAX 5 // Maximum size of the stack

using namespace std;

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Pointer to the top of the stack

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if the stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Push operation (Insert element at top)
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into the stack.\n";
    }

    // Pop operation (Remove element from top)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        cout << arr[top--] << " popped from the stack.\n";
    }

    // Peek operation (View top element without removing)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// Main function to test stack operations
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
