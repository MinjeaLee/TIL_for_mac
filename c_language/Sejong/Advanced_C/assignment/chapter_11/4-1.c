#include <stdio.h>

struct bike_info{

    int bike_id, tel, use_time, membership_type;// ������ ��ȣ, ��ȭ��ȣ, ���ð�, ����� ����
    char type, membership;// ��������� ���ϱ����� ����, ����� ���� �̰���
    double fee;// ���

};

void input(struct bike_info *p, int N){
    struct bike_info *p_struct;// ����ü ������ ����

    for(p_struct = p; p_struct < p + N; p_struct++){// p + n ��ŭ �ݺ�
        scanf("%d %d %c", &p_struct->bike_id, &p_struct->tel, &p_struct->type);// ������ ���̵�, ��ȭ��ȣ, ��ǰ �Է�
        if(p_struct->type == 'S'){// ��ǰ�� ������̸� ������ ���� �Է�
            scanf(" %c %d %d",&p_struct->membership ,&p_struct->membership_type,&p_struct->use_time);
            
        }
        else{
            scanf(" %d", &p_struct->use_time);// ���ϱ��̸� ���ð��� �Է�
        }
        getchar();// \n getchar
    }
}

void compute(struct bike_info *p, int N){
    struct bike_info *p_struct; // ����ü ������ ����
    int fee, over_time;// ���, �ʰ� �ð� ���� ���� ����

    for(p_struct = p; p_struct < p + N; p_struct++){// p + n�� ��ŭ �ݺ�
        fee = 0;// ����� 0���� �ʱ�ȭ
        over_time = p_struct->use_time - 60; // �ʰ� �ð� ��� ����

        if(over_time > 0){ // �ʰ��ð��� �ִٸ�
            fee += (over_time / 5) * 200;// 5�д� 200�� ����Ͽ� ����
        }

        if(p_struct->type == 'S'){// ��ǰ�� ������̶��
            if(p_struct->membership == 'N'){    // ����� ���� ��� + 
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
        else{   // ���ϱ��̶��
            fee += 1000; // �⺻ ��� +
        }
        p_struct->fee = fee;//����ü�� ����
    }
}

void display(struct bike_info *p, int N){
    struct bike_info *p_struct;// ����ü ������ ����

    for(p_struct = p; p_struct < p + N; p_struct++){    // ��� ���
        printf("%d %d %c %.0lf\n", p_struct->bike_id, p_struct->tel, p_struct->type, p_struct->fee);
    }
    
}


int main(){
    struct bike_info chart[100];   // ����ü �迭 ����
    int n;// ���� ���� ���� ����

    scanf("%d", &n); // ���� �Է�
    
    input(chart, n);  // �Լ� ȣ��
    compute(chart, n);
    display(chart, n);

    return 0;
}