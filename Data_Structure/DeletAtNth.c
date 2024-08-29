//Linked List: delet a node at the nth position
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* g_head;//global
int listlen = 1;

void Insert(int data); //insert an integer at the end of the list
void Print(); //print all the elements in the list
void Delete(int n); //delete node at the required position

void Insert(int data)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    
    temp1->data = data;
    temp1->next = NULL;

    if (listlen==1) {
        temp1->next = g_head;
        g_head = temp1;
    } else {
        temp2 = g_head;
        for(int i=0; i<listlen-2;i++) {
            temp2 = temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next = temp1;
    }

    listlen += 1;

}

void Print() 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = g_head;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n) 
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp1 = g_head;
    if (n==1) {
        g_head = temp1->next; //head now points to the second node
        free(temp1);
        return;
    }
    for(int i=0; i<n-2; i++) {
        temp1 = temp1->next;
    }
    //temp1 points to the (n-1)th node
    temp2 = temp1->next; // nth node 
    temp1->next = temp2->next; //(n+1)th node;
    free(temp2);
}

int main() 
{
    g_head = NULL; //empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List: 2, 4, 6, 5
    Print();

    int n;
    printf("Enter a position:\n");
    scanf("%d",&n);

    Delete(n); //(n=3) List:2, 4, 5
    Print();

    return 0;
}