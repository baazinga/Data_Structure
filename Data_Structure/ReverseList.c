//Linked List: Reverse a linked list
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};

int listlen = 1;

struct Node* Insert(struct Node* head, int data)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    
    temp1->data = data;
    temp1->next = NULL;

    if (listlen==1) {
        temp1->next = head;
        head = temp1;
    } else {
        temp2 = head;
        for(int i=0; i<listlen-2;i++) {
            temp2 = temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next = temp1;
    }

    listlen += 1;
    return (head);

}

struct Node* Reverse (struct Node* head)
{
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));

    current = head;
    prev = NULL;
    while(current!=NULL) {
        next = current->next; //store the address of the next node here 
        current->next = prev; //adjust the current node link to point to the previous one 
        prev = current; // move prev to curernt
        current = next; // move current to next
    }
    head = prev;
    return (head);

}

void Print(struct Node* head) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL; //empty list
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8); //List: 2, 4, 6, 8
    Print(head);

    head = Reverse(head);
    Print(head);

    return 0;
}