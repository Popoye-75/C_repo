#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};

struct Node *poly1 = NULL;
struct Node *poly2 = NULL;

struct Node *insert(struct Node *head, int coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation is failed ..! \n");
        return head;
    }
    newNode->expo = exp;
    newNode->coeff = coef;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;

    return head;
}

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }
    struct Node *currNode = head;
    while (currNode != NULL)
    {
        printf("%dX^%d ", currNode->coeff, currNode->expo);
        if (currNode->next != NULL)
        {
            printf(" + ");
        }
        currNode = currNode->next;
    }
    printf("\n");
}
int main()
{
    
    poly1 = insert(poly1, 3, 2);
    poly1 = insert(poly1, 2, 1);
    poly1 = insert(poly1, 5, 0);

    printList(poly1);
    return 0;
}