// Evaluate Postfix
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (top==NULL) {
        temp->data = x;
        temp->link = NULL;
        top = temp;
    } else {
        temp->data = x;
        top->link = temp;
        top = temp;
    }
    
}

int Pop()
{
    struct Node* temp = top;
    if(top==NULL) {
        printf("\nStack is empty.");
        exit;
    } else {
        top = top->link;
        return (temp->data);
    }
}

void IsEmpty()
{
    if(top == NULL) {
        printf("Empty");
    } else {
        printf("Is Not Empty");
    }
}

//------------------------------------//

int IsOperator(char x)
{
    if(x=='+'|| x=='-'|| x=='*'|| x=='/') {
        return 1;
    } else {
        return 0;
    }
}

//------------------------------------//

int main()
{
    char F[100];
    const char delimiter[2] = " ";
    char *token;
    int result, operand1, operand2,temp;
    printf("Input the formula in postfix(use space as a delimiter):\n");
    fgets(F,sizeof(F)-1, stdin );
    token = strtok(F, delimiter);

    while(token!=NULL) {
        if (IsOperator(*token)==1) {
            operand1 = Pop();
            operand2 = Pop();
            if(*token=='+') {
                result = operand2 + operand1;
            }
            if(*token=='-') {
                result = operand2 - operand1;
            }
            if(*token=='*') {
                result = operand2 * operand1;
            }if(*token=='/') {
                result = operand2 / operand1;
            }
            Push(result);
        } else {
            temp = atoi(token);
            Push(temp);
        }
        token = strtok(NULL, delimiter);
    }

    printf("\nResult: %d",top->data);
    return 0;	
}