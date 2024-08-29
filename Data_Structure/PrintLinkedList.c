//Print Linked List Using Recursion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};

void Print(struct Node* p)
{
    if ( p == NULL) {
        printf("\n");
        return;
    } //exit condition
    Print(p->next); //first recurssive call
    printf("%d ", p->data); //then print the value in the call
   
}

struct Node* Insert(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head==NULL) {
        head = temp;
    } else {
        struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
        temp1 = head;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return (head);
}

int main() 
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    head = Insert(head, 2); 
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head); 
    return 0;
}