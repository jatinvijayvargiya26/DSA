#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 100

// Structure to represent a book
typedef struct {
    char name[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
} Book;

// Stack to store returned books
Book stack[MAX_BOOKS];
int top = -1;

// Function to add a returned book to the stack
void addBook() {
    if (top == MAX_BOOKS - 1) {
        printf("Stack is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book name: ");
    fgets(stack[++top].name, MAX_NAME_LENGTH, stdin);
    stack[top].name[strcspn(stack[top].name, "\n")] = 0; // Remove newline character

    printf("Enter book author: ");
    fgets(stack[top].author, MAX_NAME_LENGTH, stdin);
    stack[top].author[strcspn(stack[top].author, "\n")] = 0; // Remove newline character

    printf("Book added successfully.\n");
}

// Function to remove the most recent book from the stack
void removeBook() {
    if (top == -1) {
        printf("Stack is empty. No books to remove.\n");
        return;
    }

    printf("Book '%s' by '%s' removed successfully.\n", stack[top].name, stack[top].author);
    top--;
}

// Function to view the most recent book in the stack
void viewRecentBook() {
    if (top == -1) {
        printf("Stack is empty. No books to view.\n");
        return;
    }

    printf("Most recent book: '%s' by '%s'\n", stack[top].name, stack[top].author);
}

// Function to display all books in the stack
void displayBooks() {
    if (top == -1) {
        printf("Stack is empty. No books to display.\n");
        return;
    }

    printf("Returned books:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d. '%s' by '%s'\n", i + 1, stack[i].name, stack[i].author);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nBook Management System\n");
        printf("1. Add a returned book\n");
        printf("2. Remove the most recent book\n");
        printf("3. View the most recent book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                viewRecentBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}