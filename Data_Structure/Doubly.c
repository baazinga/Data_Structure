// Doubly Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* g_head;

struct Node* GetNewNode(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    (*newNode).data = x;
    (*newNode).next = NULL;
    (*newNode).prev = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x);
    if (g_head == NULL) {
        g_head = newNode;  // g_head store the address of the new node
        return;
    }
    g_head->prev = newNode;
    newNode->next = g_head;
    g_head = newNode; // g_head store the address of the new node
}

void InsertAtTail(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(g_head == NULL) {
        g_head = newNode;
        return;
    }
    struct Node* temp = g_head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}

void Print()
{
    struct Node* temp = g_head;
    printf("Forward: ");
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node* temp = g_head;
    if (temp==NULL) {
        return; //empty list
    }
    //traverse to the last node
    while(temp->next!=NULL) {
        temp = temp->next; 
    }
    printf("Reverse: ");
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    g_head = NULL; //empty list.
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtTail(1); Print(); ReversePrint();
    return 0;
}