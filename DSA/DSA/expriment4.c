#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

// Structure to represent a customer
typedef struct {
    int id;
    char name[20];
} Customer;

// Queue to store customers
Customer queue[MAX_CUSTOMERS];
int front = -1;
int rear = -1;

// Function to add a customer to the queue
void enqueue(Customer customer) {
    if ((rear + 1) % MAX_CUSTOMERS == front) {
        printf("Queue is full. Cannot add more customers.\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_CUSTOMERS;
    }

    queue[rear] = customer;
    printf("Customer added to the queue successfully.\n");
}

// Function to remove a customer from the queue
Customer dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. No customers to serve.\n");
        exit(0);
    }

    Customer customer = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_CUSTOMERS;
    }

    printf("Customer %d served.\n", customer.id);
    return customer;
}

// Function to display the queue
void displayQueue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. No customers to display.\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("Customer %d: %s\n", queue[i].id, queue[i].name);
        i = (i + 1) % MAX_CUSTOMERS;
    }
    printf("Customer %d: %s\n", queue[rear].id, queue[rear].name);
}

int main() {
    int choice;
    Customer customer;

    while (1) {
        printf("\nCustomer Service Queue Management System\n");
        printf("1. Add a customer to the queue\n");
        printf("2. Serve the next customer\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID: ");
                scanf("%d", &customer.id);
                printf("Enter customer name: ");
                scanf("%s", customer.name);
                enqueue(customer);
                break;
            case 2:
                customer = dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}