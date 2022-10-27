#include <stdio.h>

struct bike_info{

    int bike_id, tel, use_time, membership_type;
    char type, membership;
    double fee;

};

void input(struct bike_info *p, int N){
    struct bike_info *p_struct;

    for(p_struct = p; p_struct < p + N; p_struct++){
        scanf("%d %d %c", &p_struct->bike_id, &p_struct->tel, &p_struct->type);
        if(p_struct->type == 'S'){
            scanf(" %c %d %d",&p_struct->membership ,&p_struct->membership_type,&p_struct->use_time);
            
        }
        else{
            scanf(" %d", &p_struct->use_time);
        }
        getchar();
    }
}

void compute(struct bike_info *p, int N){
    struct bike_info *p_struct;
    int fee, over_time;

    for(p_struct = p; p_struct < p + N; p_struct++){
        fee = 0;
        over_time = p_struct->use_time - 60;

        if(over_time > 0){
            fee += (over_time / 5) * 200;
        }

        if(p_struct->type == 'S'){
            if(p_struct->membership == 'N'){    // 가입 비용 + 초과비용
                if(p_struct->membership_type == 7){
                    fee += 3000;
                }
                else if(p_struct->membership_type == 30){
                    fee += 5000;
                }
                else{
                    fee += 15000;
                }
                
            }

        }
        else{   // 일일권
            fee += 1000;
        }
        p_struct->fee = fee;
    }
}

void display(struct bike_info *p, int N){
    struct bike_info *p_struct;
    for(p_struct = p; p_struct < p + N; p_struct++){
        printf("%d %d %c %.0lf\n", p_struct->bike_id, p_struct->tel, p_struct->type, p_struct->fee);
    }
    
}


int main(){
    struct bike_info chart[100];
    int n;

    scanf("%d", &n);
    
    input(chart, n);
    compute(chart, n);
    display(chart, n);

    return 0;
}