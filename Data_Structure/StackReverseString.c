// Reverse string using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* link;
};

struct Node* top = NULL; // Initialize top to NULL

void Push(char x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop() {
    if (top == NULL) {
        return;
    }
    struct Node* temp = top;
    top = top->link;
    free(temp);
}

int IsEmpty() {
    return top == NULL;
}

char Top() {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

void Reverse(char* C, int n) {
    for (int i = 0; i < n; i++) {
        Push(C[i]);
    }
    for (int i = 0; i < n; i++) {
        C[i] = Top();
        Pop();
    }
}

int main() {
    char C[51];
    printf("Enter a string:\n");
    fgets(C, sizeof(C), stdin); // Use fgets instead of gets
    int len = strlen(C);
    if (C[len - 1] == '\n') {
        C[len - 1] = '\0'; // Remove the newline character
        len--; // Adjust the length
    }
    Reverse(C, len);
    printf("Output = %s\n", C);
    return 0;
}