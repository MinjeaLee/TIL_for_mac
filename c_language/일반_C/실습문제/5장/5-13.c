// #include <stdio.h>

// int main(){
//     double k, e, m, aver;
//     scanf("%lf %lf %lf", &k, &e, &m);
//     aver = (k + e + m)/3;
//     printf("%.2lf\n", aver);
//     if (aver >= 75){
//         printf("A");
//     }
//     else if(aver >= 50){
//         printf("B");
//     }
//     else{
//         printf("F");
//     }

//     return 0;
// }



#include <stdio.h>

int main(){
    double k, e, m, aver;
    int result;
    scanf("%lf %lf %lf", &k, &e, &m);
    aver = (k + e + m)/3;
    printf("%.2lf\n", aver);

    switch((int) aver){
        case 100:
        case 99:
        case 98:
        case 97:
        case 96:
        case 95:
        case 94:
        case 93:
        case 92:
        case 91:
        case 90:
        case 89:
        case 88:
        case 87:
        case 86:
        case 85:
        case 84:
        case 83:
        case 82:
        case 81:
        case 80:
        case 79:
        case 78:
        case 77:
        case 76:
        case 75: printf("A"); break;
        case 74:
        case 73:
        case 72:
        case 71:
        case 70:
        case 69:
        case 68:
        case 67:
        case 66:
        case 65:
        case 64:
        case 63:
        case 62:
        case 61:
        case 60:
        case 59:
        case 58:
        case 57:
        case 56:
        case 55:
        case 54:
        case 53:
        case 52:
        case 51:
        case 50: printf("B"); break;
        default: printf("F"); break;
    }

    return 0;
}
