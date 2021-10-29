#include <stdio.h>

struct bike_info{

    int bike_id, tel, use_time, membership_type;        // ������ ��ȣ, ��ȭ��ȣ, ���ð�, ����� ����
    char type, membership;  // ��������� ���ϱ����� ����, ����� ���� �̰���
    double fee; // ��� 

};

void input(struct bike_info *p, int N){
    struct bike_info *p_struct;     // ����ü ������ ����

    for(p_struct = p; p_struct < p + N; p_struct++){    // p + n ��ŭ �ݺ�
        scanf("%d %d %c", &p_struct->bike_id, &p_struct->tel, &p_struct->type);     // ������ ���̵�, ��ȭ��ȣ, ��ǰ �Է�
        if(p_struct->type == 'S'){  // ��ǰ�� ������̸� ������ ���� �Է�
            scanf(" %c %d %d",&p_struct->membership ,&p_struct->membership_type,&p_struct->use_time);
            
        }
        else{
            scanf(" %d", &p_struct->use_time);      // ���ϱ��̸� ���ð��� �Է�
        }
        getchar();  // \n getchar
    }
}

void compute(struct bike_info *p, int N){
    struct bike_info *p_struct;         // ����ü ������ ����
    int fee, over_time;     // ���, �ʰ� �ð� ���� ���� ����

    for(p_struct = p; p_struct < p + N; p_struct++){        // p + n�� ��ŭ �ݺ�
        fee = 0; // ����� 0���� �ʱ�ȭ
        over_time = p_struct->use_time - 60;    // �ʰ� �ð� ��� ����

        if(over_time > 0){  // �ʰ��ð��� �ִٸ�
            fee += (over_time / 5) * 200;       // 5�д� 200�� ����Ͽ� ����
        }

        if(p_struct->type == 'S'){ // ��ǰ�� ������̶��
            if(p_struct->membership == 'N'){    // ������� ���ٸ�
                if(p_struct->membership_type == 7){ // ����� ���� ��� + 
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
        else{   // ���ϱ��̶��
            fee += 1000;    // �⺻ ��� +
        }
        p_struct->fee = fee;    //����ü�� ����
    }
}

void display(struct bike_info *p, int N){   
    struct bike_info *p_struct; // ����ü ������ ����
    int d_total_fee = 0, s_total_fee = 0;
    // ���ϱ� ���, ����� ��� ���� ���� ����

    for(p_struct = p; p_struct < p + N; p_struct++){
        printf("%d %d %c %.0lf\n", p_struct->bike_id, p_struct->tel, p_struct->type, p_struct->fee);    // ���� ���
        if(p_struct->type == 'D'){      // ���ϱ��� ���
            d_total_fee += p_struct->fee;   // ���ϱ� ��� ������ +
        }
        else{   
            s_total_fee += p_struct->fee;       // ������� ��� ����� ��� ������ +
        }
    }
    printf("%d %d %d", d_total_fee, s_total_fee, d_total_fee + s_total_fee);        // ��� ���� ���
    
}

void sort_(struct bike_info *p, int N){     // ���� �Լ��� ���� �Լ��� ����
    struct bike_info *p_i, *p_j, tmp;       // ����ü ������, ���Ұ������� �ʿ��� ����ü ���� ����

    for(p_i = p; p_i < p + N - 1; p_i++){       // �������� ��� ���
        for(p_j = p_i + 1; p_j < p + N; p_j++){     
            if(p_i->bike_id > p_j->bike_id){        // ������ ���̵� ���� ���� ����
                tmp = *p_i;                 // ���� ����
                *p_i = *p_j;
                *p_j = tmp;
            }
        }
    }

}

void bike_info_sort(struct bike_info *p, int N){
    struct bike_info *p_i, *p_j, s[100], d[100];       // ����ü ������, ������� ���� ���ϱ��� ��� ���� ������ �迭 ����
    int D_count = 0, S_count = 0;       // �� �迭�� �ε��� ���� ����
    for(p_i = p; p_i < p + N; p_i++){       // n�� �ݺ�
        if(p_i->type == 'S'){       // ������� ���
            s[S_count] = *p_i;      // ����� �迭�� ����
            S_count++;              // ����� �ε��� ++
        }
        else{
            d[D_count] = *p_i;      // ���ϱ��� ��� ���ϱ� �迭�� ����
            D_count++;              // ���ϱ� �ε��� ++
        }
    }
    sort_(s, S_count);      // �� �迭 ����
    sort_(d, D_count);

    for(int i = 0; i < D_count; i++){   // ���ĵ� �� �迭�� �ϳ��� �迭�� ����� ����, d �迭 ���� ����, d �迭 ���� ���� ��ŭ �ݺ�
        *(p + i) = d[i];        // ����
    }
    for(int i = D_count; i < D_count + S_count; i++){       // d���Ұ����� �ε��� ���� ����
        *(p + i) = s[i - D_count];      // ����
    }
}



int main(){
    struct bike_info chart[100];        // ����ü �迭 ����
    int n;                              // ���� ���� ���� ����

    scanf("%d", &n);                    // ���� �Է�
    
    input(chart, n);                // �Լ� ȣ��
    compute(chart, n);
    bike_info_sort(chart, n);
    display(chart, n);

    return 0;
}