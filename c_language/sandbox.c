// 4x4 board가 나올 수 있는 경우의 수를 모두 출력하시오
// 숫자 1 2 3 4를 사용하여 4x4 board를 만들 수 있는 경우의 수를 모두 출력하시오
// 각 행과 열에는 중복된 숫자가 없어야 한다

#include <stdio.h>

int main(void)
{
    char a[24][4];
    char board[4][4];
    int index_1d = 0;
    int i, j, k, l;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if (j == i)
                continue;
            for (k = 1; k <= 4; k++)
            {
                if (k == i || k == j)
                    continue;
                for (l = 1; l <= 4; l++)
                {
                    if (l == i || l == j || l == k)
                        continue;
                    a[index_1d][0] = i;
                    a[index_1d][1] = j;
                    a[index_1d][2] = k;
                    a[index_1d++][3] = l;   
                }
            }
        }
    }

    int board_index = 0;
    for (i = 0; i < 24; i++){
        for (j = 0; (a[i][0] == a[j][0]) && j < 24; j++){
            
        }
    }


    return 0;
}