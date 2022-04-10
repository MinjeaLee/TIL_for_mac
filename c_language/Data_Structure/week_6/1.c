#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct list {
   int coef;
   int exp;
   struct list* next;
};

int main()
{
   struct list* header_first = (struct list*)malloc(sizeof(struct list));
   struct list* header_sec = (struct list*)malloc(sizeof(struct list));

   int first;
   scanf("%d", &first);
   struct list* tmp = header_first;

   for (int i = 0; i < first; i++)
   {
      struct list* p = (struct list*)malloc(sizeof(struct list) * 1);
      tmp->next = p;
      tmp = tmp->next;
      scanf("%d %d", &(tmp->coef), &(tmp->exp));
   }

   tmp->next = NULL;

   int second;
   scanf("%d", &second);
   struct list* tmp2 = header_sec;
   for (int i = 0; i < second; i++)
   {


      struct list* p = (struct list*)malloc(sizeof(struct list) * 1);
      tmp2->next = p;
      tmp2 = tmp2->next;
      scanf("%d %d", &(tmp2->coef), &(tmp2->exp));

   }
   tmp2->next = NULL;
   tmp = header_first;
   tmp2 = header_sec;
   tmp = tmp->next;
   tmp2 = tmp2->next;
   while (1)
   {

      if (tmp != NULL && tmp2 != NULL)
      {
         if (tmp->exp > tmp2->exp)
         {
            if (tmp->coef != 0)
            {
               printf(" %d", tmp->coef);
               printf(" %d", tmp->exp);
            }
            tmp = tmp->next;
            if (tmp == NULL && tmp2 == NULL)
            {

               break;
            }
         }
         else if (tmp->exp < tmp2->exp)
         {
            if (tmp2->coef != 0)
            {
               printf(" %d", tmp2->coef);
               printf(" %d", tmp2->exp);
            }
            tmp2 = tmp2->next;
            if (tmp == NULL && tmp2 == NULL)
            {

               break;
            }
         }
         else if (tmp->exp == tmp2->exp)
         {
            if (tmp->coef + tmp2->coef != 0)
            {
               printf(" %d", tmp->coef + tmp2->coef);
               printf(" %d", tmp->exp);
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
            if (tmp == NULL && tmp2 == NULL)
            {

               break;
            }
         }
      }
      else if (tmp == NULL && tmp2 != NULL)
      {
         if (tmp2->coef != 0)
         {
            printf(" %d", tmp2->coef);
            printf(" %d", tmp2->exp);
         }
         tmp2 = tmp2->next;
         if (tmp == NULL && tmp2 == NULL)
         {

            break;
         }
      }
      else if (tmp2 == NULL && tmp != NULL)
      {
         if (tmp->coef != 0)
         {
            printf(" %d", tmp->coef);
            printf(" %d", tmp->exp);
         }
         tmp = tmp->next;
         if (tmp == NULL && tmp2 == NULL)
         {

            break;
         }
      }
   }
   return 0;
}