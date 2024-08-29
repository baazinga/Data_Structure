//Linked List: Inserting a node at nth position

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* g_head;

void Insert(int data, int n); //data to insert & its postition
void Print();

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
    g_head = NULL; //empty list
    Insert(2,1); //List: 2
    Insert(3,2); //List: 2,3
    Insert(4,1); //List: 4,2,3
    Insert(5,2); //List: 4,5,2,3
    Print();
    return 0;
}