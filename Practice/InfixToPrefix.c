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
        printf("%c", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

void reverse(char exp[])
{
    int i = 0, j = 0;
    char ch;
    while (exp[i] != '\0')
    {
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
    // /* Verification section for verify reverse expression
    // int k = 0;
    // while(exp[k]!='\0'){
    //     printf("%c",exp[k]);
    //     k++;
    // }
    // k--;
    // printf("\n");
    // printf("i: %d ,j: %d ,k: %d \n",i,j,k);
}

int isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

// int precedence(char ch)
// {
// }

char associativity(char ch)
{
    if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
    {
        return 'L';
    }
    return 'R';
}

void prefix(char exp[])
{
    char prefix[100];
    reverse(exp); // Step == 1 To reverse the expression
    int i = 0;
    while (exp[i] != '\0') // Step == 2 Traverse till null character
    {
        if (isOperand(exp[i])) // Step == 3 push or add into prefix
        {
            prefix[i] = exp[i];
        }
        i++;
    }
    // prefix[i] = '\0';
    printf("%s \n",prefix);
}
int main()
{
    char exp[] = "((5+3)*2)-(8/4)";
    prefix(exp);

    return 0;
}