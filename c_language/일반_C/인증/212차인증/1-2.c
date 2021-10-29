#include <stdio.h>

int main()
{
    char input;
    int k, l, x[100] = { 0, }, i, n, m, sort[100] = {0, }, j, temp;
    scanf("%d %d", &n, &m);
    getchar();
    while (1)
    {
        scanf("%c %d %d", &input, &k, &l);
        getchar();
        if (input == 'n')
        {
            break;
        }
        if (k > n || l > m)
        {
            printf("please input correctly\n");
        }
        else if (x[k - 1] != 0)
        {
            printf("please select another room\n");
        }
        else
        {
            x[k - 1] = l;
            sort[k - 1] = l;
            for (i = 0; i < n; i++)
            {
                printf("%d ", x[i]);
            }
            printf("\n");
        }
    }
/
    for (i = 0; i < n -1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (sort[i] < sort[j])
            {
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    
    for(i = 0; i < n; i++){
        if(sort[i] == 0){
            break;
        }
        for(j = i + 1; j < n; j++){
            if(sort[i] == x[j]){
                printf("%d %d\n", j + 1, sort[i]);
                break;
            }
        }
    }

    return 0;
}