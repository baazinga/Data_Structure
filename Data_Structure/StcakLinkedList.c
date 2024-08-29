// Stack : Linked List Implenmentation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL; //head empty by default

void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop() 
{
    struct Node* temp;
    if (top == NULL) {
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

void IsEmpty()
{
    if (top == NULL) {
        printf("True");
    } else {
        printf("False");
    }
}

void Top()
{
    printf("Top: %d\n", top->data);
}

void Print()
{
    struct Node* temp = top;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n"); 
}

int main()
{
    Push(2);Print();
    Push(5);Print();
    Pop();Print();
    Top();Print();
    Pop();Print();
    IsEmpty();
    return 0;
}