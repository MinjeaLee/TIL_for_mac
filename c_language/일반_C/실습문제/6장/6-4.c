// for¹®
#include <stdio.h>

int main(){
    int a, b, result, i;
    scanf("%d %d", &a, &b);
    if (a < b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    for(i = 1; i <= a; i++){
        if(a % i == 0 && b % i == 0){
            result = i;
        }
    }
    printf("%d", result);

    return 0;
}

// while¹®
// #include <stdio.h>

// int main(){
//     int a, b, result, i = 1;
//     scanf("%d %d", &a, &b);
//     if (a < b){
//         int temp;
//         temp = a;
//         a = b;
//         b = temp;
//     }
//     while(i <= a){
//         if(a % i == 0 && b % i == 0){
//             result = i;
//         }
//         i++;
//     }
//     printf("%d", result);

//     return 0;
// }