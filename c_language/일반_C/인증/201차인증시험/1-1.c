#include <stdio.h>

int main(){
    int kor1, kor2, eng1, eng2;
    int result1, result2;
    int max;
    scanf("%d %d %d %d", &kor1, & eng1, &kor2, &eng2);
    result1 = (kor1 + eng1)/2;
    result2 = (kor2 + eng2)/2;
    if(result1 > result2){
        max = result1;
    }
    else{
        max = result2;
    }
    if(kor1 < 60 || kor2 < 60 || eng1 < 60|| eng2 <60){
        printf("F");
    }
    else if(max >= 90){
        printf("A+");
    }
    else if(max >=80){
        printf("A");
    }
    else if(max >= 70){
        printf("B+");
    }
    else if(max >= 60){
        printf("B");
    }
    



    return 0;
}