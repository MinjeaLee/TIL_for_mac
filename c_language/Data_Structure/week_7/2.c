#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
struct node
{
    int num;
    struct node *next;
};
struct node *union1(struct node *A, struct node *B)
{
    struct node *new = (struct node *)malloc(sizeof(struct node) * 1);
    struct node *tmp = new;
    tmp->next = NULL;
    A = A->next;
    B = B->next;
    for (; A || B;)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
        if (A && B)
        {
            if (A->num < B->num)
            {
                p->num = A->num;
                A = A->next;
            }
            else if (A->num > B->num)
            {
                p->num = B->num;
                B = B->next;
            }
            else
            {
                p->num = B->num;
                A = A->next;
                B = B->next;
            }
        }
        else if (A)
        {
            p->num = A->num;
            A = A->next;
        }
        else if (B)
        {
            p->num = B->num;
            B = B->next;
        }
        tmp->next = p;
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return new;
}
struct node *intersect(struct node *A, struct node *B)
{
    struct node *new = (struct node *)malloc(sizeof(struct node) * 1);
    struct node *tmp = new;
    tmp->next = NULL;
    A = A->next;
    B = B->next;
    struct node *Atmp = A;
    while (Atmp)
    {
        struct node *Btmp = B;
        while (Btmp)
        {
            if (Atmp->num == Btmp->num)
            {
                struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
                p->num = Atmp->num;
                tmp->next = p;
                tmp = tmp->next;

                break;
            }
            else
            {
                Btmp = Btmp->next;
            }
        }
        Atmp = Atmp->next;
    }
    tmp->next = NULL;
    return new;
}
int main()
{
    int A_size;
    struct node *A_header = (struct node *)malloc(sizeof(struct node) * 1);
    A_header->next = NULL;
    scanf("%d", &A_size);
    struct node *tmp = A_header;
    for (int i = 0; i < A_size; i++)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
        scanf("%d", &p->num);
        tmp->next = p;
        tmp = tmp->next;
    }
    tmp->next = NULL;

    int B_size;
    struct node *B_header = (struct node *)malloc(sizeof(struct node) * 1);
    B_header->next = NULL;
    scanf("%d", &B_size);
    struct node *tmp2 = B_header;
    for (int i = 0; i < B_size; i++)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node) * 1);
        scanf("%d", &p->num);
        tmp2->next = p;
        tmp2 = tmp2->next;
    }
    tmp2->next = NULL;
    struct node *new1 = union1(A_header, B_header);
    struct node *new2 = intersect(A_header, B_header);
    if (new1->next == NULL)
    {
        printf(" 0");
    }
    else
    {
        while (1)
        {
            new1 = new1->next;
            if (new1 == NULL)
            {
                break;
            }
            printf(" %d", new1->num);
        }
    }
    printf("\n");
    if (new2->next == NULL)
    {
        printf(" 0");
    }
    else
    {
        while (1)
        {
            new2 = new2->next;
            if (new2 == NULL)
            {
                break;
            }
            printf(" %d", new2->num);
        }
    }
    return 0;
}