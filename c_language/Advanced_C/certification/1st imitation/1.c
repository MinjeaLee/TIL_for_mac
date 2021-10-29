#include <stdio.h>

void input(int *p, int M){
    int *p_i;

    for(p_i = p; p_i < p + M; p_i++){
        scanf("%d", p_i);
    }
}

int *sel_max(int *p, int M){
    int *p_i, *p_j, *p_max;
    int count, max_count = -1;

    for(p_i = p; p_i < p + M; p_i++){
        count = 0;
        for(p_j = p; p_j < p + M; p_j++){
            if(*p_i == *p_j){
                count++;
            }
        }
        if(max_count < count) {
            max_count = count;
            p_max = p_i;
        }
    }

    return p_max;
}

void output(int *p, int N){
    int *p_i;
    for(p_i = p; p_i < p + N; p_i++){
        printf(" %d", *p_i);
    }
}


int main(void){
    int in[100], out[100], *max, i, N, M;
    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++){
        input(in, M);
        max=sel_max(in, M);
        out[i]=*max;
    }

    output(out, N);

    return 0;
}