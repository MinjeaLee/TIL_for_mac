 #include <stdio.h>
//restore github
int main(){
    int x[100], y[100], a[100], b[100], c[100], a_c, b_c, n, i, j, tmp;
    int acount = 0, bcount = 0, ccount = 0;
    double a_total = 0, b_total = 0, c_total = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
        y[i] = x[i];
    }
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(y[i] < y[j]){
                tmp = y[i];
                y[i] = y[j];
                y[j] = tmp;
            }
        }
    }
    for(i = 1; i < n; i++){
        if(y[i] == y[i-1]){
            y[i-1] = -1;
        }
    }   
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(x[i] == y[j]){
                printf("%d ", j + 1);
                break;
            }
        }
    }
    printf("\n");
    a_c = n * 0.3 - 1;
    b_c = n * 0.7 - 1;
    for(i = 0; i < n; i++){
        if(y[a_c] <= x[i]){
            printf("A ");
            a[acount] = x[i];
            acount++;
        }
        else if(y[a_c] > x[i] && y[b_c] <= x[i]){
            printf("B ");
            b[bcount] = x[i]; 
            bcount++;
        }
        else{
            printf("C ");
            c[ccount] = x[i];
            ccount++;
        }
    }
    
    for(i = 0; i < acount; i++){
        a_total += a[i];
    }
    
    for(i = 0; i < bcount; i++){
        b_total += b[i];
    }
    
    for(i = 0; i < ccount; i++){
        c_total += c[i];
    }
    printf("\n%0.1lf %0.1lf %0.1lf", a_total / acount, b_total / bcount, c_total / ccount);
    
    
    return 0;
}