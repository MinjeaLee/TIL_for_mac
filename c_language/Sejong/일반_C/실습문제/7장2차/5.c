#include <stdio.h> 

int arrsum(int x[], int s, int e);

int main(){
    int x[100], s, e, n;
    scanf("%d %d %d", &n, &s , &e);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }

    printf("%d", arrsum(x, s, e));

    return 0;
}

int arrsum(int x[], int s, int e){
    int result = 0;
    for(int i = s; i <= e; i++){
        result += x[i];
    }
    return result;
}
