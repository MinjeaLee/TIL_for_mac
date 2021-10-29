#include <stdio.h>

struct result{
    int max, min, pass_diff, diff; 
    char pnp;
};

void passorfail(struct result *p){
    if(p -> diff <= p -> pass_diff){
        p -> pnp = 'P';
    }
    else{
        p->pnp = 'F';
    }
}

int main(){
    struct result result;

    scanf("%d %d %d", &result.max, &result.min, &result.pass_diff);
    result.diff = result.max - result.min;
    passorfail(&result);
    printf("%d %c", result.diff, result.pnp);

    return 0;
}