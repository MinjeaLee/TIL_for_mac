#include <stdio.h>

struct chart{
    int sex, weight, height
};

int male(struct chart st){
    int weight = st.weight, height = st.height; 
    if((weight < 60 && height < 165) || (60 <= weight && weight < 70 && 165 <= height && height < 175) ||(70 <= weight && 175 <= height)){
        return 1;
    }
    else if((weight < 60 && 165 <= height && height < 175) || (60 <= weight && weight < 70 &&175 <= height) || (70 <= weight && height < 165)){
        return 2;
    }
    else{
        return 3;
    }
}
int female(struct chart st){
    int weight = st.weight, height = st.height; 
    if((weight < 50 && height < 165) || (50 <= weight && weight < 60 && 165 <= height && height < 175) ||(60 <= weight && 175 <= height)){
        return 1;
    }
    else if((weight < 50 && 165 <= height && height < 175) || (50 <= weight && weight < 60 &&175 <= height) || (60 <= weight && height < 165)){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){
    int n, grade_1 = 0, grade_2 = 0, grade_3 = 0, grade;
    struct chart st[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &st[i].sex, &st[i].weight, &st[i].height);
    }
    for(int i = 0; i < n; i++){
        if(st[i].sex == 1){
            grade = male(st[i]);
            if(grade == 1){
                grade_1++;
            }
            else if(grade == 2){
                grade_2++;
            }
            else{
                grade_3++;
            }
        }
        else{
            grade = female(st[i]);
            if(grade == 1){
                grade_1++;
            }
            else if(grade == 2){
                grade_2++;
            }
            else{
                grade_3++;
            }
        }
    }

    printf("%d %d %d", grade_1, grade_2, grade_3);


    return 0;
}