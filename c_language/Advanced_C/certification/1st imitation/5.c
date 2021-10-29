#include <stdio.h>
#include <string.h>

typedef struct list{
    char class[51];
    int id;

}stu;

int main(){
    stu st[100], tmp;
    int n;

    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++) {
        gets(st[i].class);
        scanf("%d", &st[i].id);
        getchar();
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(st[i].class, st[j].class) > 0){
                tmp = st[j];
                st[j] = st[i];
                st[i] = tmp;
            }
            else if(strcmp(st[i].class, st[j].class) == 0){
                if(st[i].id > st[j].id){
                    tmp = st[j];
                    st[j] = st[i];
                    st[i] = tmp;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s %d\n", st[i].class, st[i].id);
    }

    
    return 0;
}