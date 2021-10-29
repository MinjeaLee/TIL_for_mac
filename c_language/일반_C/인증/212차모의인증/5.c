#include <stdio.h>

int isLeapYear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}
int getTotalNumberOfLeapYear(int startYear, int endYear){
    int count = 0;
    for(int i = startYear; i <= endYear; i++){
        if(isLeapYear(i) == 1){
            count++;
        }
    }
    return count;
}

int main(void) {
    int startYear=0, endYear=0;
    scanf("%d %d", &startYear, &endYear);
    printf("%d", getTotalNumberOfLeapYear(startYear,endYear));

    return 0;
}