#include <stdio.h>

struct day{
    int year, month, day;
};

struct day *select_min(struct day *x, struct day *y){
    if(x -> year == y -> year){
        if(x->month == y -> month){
            if(x -> day < y -> day){
                return x;
            }
            else{
                return y;
            }
        }
        else if(x ->month < y ->month){
            return x;
        }
        else{
            return y;
        }
        
    }
    else if(x -> year < y -> year){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    struct day x, y, *result;

    scanf("%d/%d/%d\n%d/%d/%d", &x.year, &x.month, &x.day, &y.year, &y.month, &y.day);

    result = select_min(&x, &y);
    printf("%d/%d/%d",result -> year, result -> month, result -> day);

    return 0;
}