//Reverse a Linked List using Recursion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* g_head;

void Reverse(struct Node* p)
{
    //exit condition
    if(p->next == NULL) {
        g_head = p;
        return;
    }
    Reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void Insert(int data, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    //temp1: the data to insert
    temp1->data = data;
    temp1->next = NULL;
    if (n==1) {
        temp1->next = g_head;
        g_head = temp1;
        return;
    } else {
        temp2 = g_head;
        //traversal to find the right placeL:
        for (int i=0; i<n-2; i++) {
            temp2 = temp2->next;
        }
    }
    
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = g_head;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n"); 
}

int main(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    g_head = NULL; //empty list
    Insert(2,1); //List: 2
    Insert(3,2); //List: 2,3
    Insert(4,1); //List: 4,2,3
    Insert(5,2); //List: 4,5,2,3
    Print();
    p = g_head;
    Reverse(p);
    Print();
    return 0;
}

