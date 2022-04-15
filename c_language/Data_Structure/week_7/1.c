#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
struct node
{
    int num;
    struct node *next;
};
int subset(struct node *A, struct node *B)
{
    int flag = 1;
    struct node *tmp = A;
    struct node *tmp2 = B;
    if (tmp->next == NULL)
    {
        return 0;
    }

    else
    {
        tmp2 = tmp2->next;
        tmp = tmp->next;
        while (1)
        {
            if (tmp2 == NULL)
            {
                break;
            }
            if (tmp2->num == tmp->num)
            {
                tmp = tmp->next;
                if (tmp == NULL)
                {
                    flag = -1;
                    break;
                }
            }
            tmp2 = tmp2->next;
        }
        if (flag == 1)
        {
            return tmp->num;
        }
        else if (flag == -1)
        {
            return 0;
        }
    }
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
    printf("%d", subset(A_header, B_header));
    return 0;
}