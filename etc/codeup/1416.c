#include <stdio.h>


int main(){
    int num, x[100000], position = 0;
    scanf("%d", &num);

    while (1){

        x[position] = num % 2;    // 2로 나누었을 때 나머지를 배열에 저장
        num = num / 2;             // 2로 나눈 몫을 저장         
        position++;    // 자릿수 변경         
        if (num == 0)    // 몫이 0이 되면 반복을 끝냄
            break;
    }
    for(int i = position - 1; i >= 0; i--){
        printf("%d", x[i]);
    }


    return 0;
}

#include
i+=:
i+
// #include <stdio.h>

// int main()
// {
//     int decimal = 13;
//     int binary[20] = { 0, };

//     int position = 0;
//     while (1)
//     {
//         binary[position] = decimal % 2;    // 2로 나누었을 때 나머지를 배열에 저장
//         decimal = decimal / 2;             // 2로 나눈 몫을 저장

//         position++;    // 자릿수 변경

//         if (decimal == 0)    // 몫이 0이 되면 반복을 끝냄
//             break;
//     }

//     // 배열의 요소를 역순으로 출력
//     for (int i = position - 1; i >= 0; i--)
//     {
//         printf("%d", binary[i]);
//     }

//     printf("\n");

//     return 0;
// }