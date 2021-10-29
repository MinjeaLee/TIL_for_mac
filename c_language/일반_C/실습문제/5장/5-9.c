#include <stdio.h>

int main(){
    int a_y, a_m, a_d, b_y, b_m, b_d;
    scanf("%d/%d/%d", &a_y, &a_m, &a_d);
    scanf("%d/%d/%d", &b_y, &b_m, &b_d);
    if (a_y == b_y && a_m == b_m && a_d == b_d){
        printf("%04d/%02d/%02d*",a_y, a_m, a_d);
    }
    else if(a_y < b_y){
        printf("%04d/%02d/%02d", a_y, a_m, a_d);
    }
    else if(a_y > b_y){
        printf("%04d/%02d/%02d", b_y, b_m, b_d);
    }
    else{
        if(a_m < b_m){
            printf("%04d/%02d/%02d", a_y, a_m, a_d);
        }
        else if(a_m > a_y){
            printf("%04d/%02d/%02d", b_y, b_m, b_d);
        }
        else{
            if(a_d < b_d){
                printf("%04d/%02d/%02d", a_y, a_m, a_d);
            }
            else{
                printf("%04d/%02d/%02d", b_y, b_m, b_d);
            }            
        }
    }
    return 0;

}

// #include <stdio.h>

// int main(){
//     int a_y, a_m, a_d, b_y, b_m, b_d;
//     scanf("%d/%d/%d", &a_y, &a_m, &a_d);
//     scanf("%d/%d/%d", &b_y, &b_m, &b_d);
//     if(a_y > b_y){
//         printf("%04d/%02d/%02d",b_y, b_m, b_d);
//     }
//     else if(a_y < b_y){
//         printf("%04d/%02d/%02d",a_y, a_m, a_d);
//     }
//     else if(a_y == b_y && a_m > b_m){
//         printf("%04d/%02d/%02d",b_y, b_m, b_d);
//     }
//     else if(a_y == b_y && a_m < b_m){
//         printf("%04d/%02d/%02d",a_y, a_m, a_d);
//     }
//     else if(a_y == b_y && a_m == b_m && a_d > b_d){
//         printf("%04d/%02d/%02d",b_y, b_m, b_d);
//     }
//     else if(a_y == b_y && a_m == b_m && a_d < b_d){
//         printf("%04d/%02d/%02d",a_y, a_m, a_d);   
//     }
//     else{
//         printf("%04d/%02d/%02d*",a_y, a_m, a_d);
//     }
//     return 0;
// }