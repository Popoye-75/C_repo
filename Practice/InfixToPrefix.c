#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;

void push(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty ..!\n");
        return '\0';
    }
    struct Node *temp = top;
    char ch = temp->data;
    top = top->next;
    free(temp);
    return ch;
}

void printStack()
{
    if (top == NULL)
    {
        printf("empty\n");
        return;
    }
    struct Node *currNode = top;
    while (currNode != NULL)
    {
        printf("%c \n", currNode->data);
        currNode = currNode->next;
    }
}

void reverse(char exp[])
{
    int i = 0,j = 0;
    char ch;
    while(exp[i] !='\0'){
        i++;
    }
    i--;

    while (j < i)
    {
        ch = exp[j];
        exp[j] = exp[i];
        exp[i] = ch;
        j++;
        i--;
    }
    int k = 0;
    while(exp[k]!='\0'){
        push(exp[k]);
        k++;
    }
    printf("\n");
    printStack();
}

// void prefix(char exp[])
// {
//     reverse(exp);
// }
int main()
{
    char exp[] = "((5+3)*2)-(8/4)";
    
    reverse(exp);
    // prefix(exp);

    return 0;
}