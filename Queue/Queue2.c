#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX], front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to insert an element into the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 when first element is inserted
    }
    queue[++rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Reset when last element is removed
    } else {
        front++;
    }
}

// Function to get the front element without removing it (Peek)
void peek() {
    if (isEmpty()) {
        printf("Queue is empty! No front element.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to test the queue operations
int main() {
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
