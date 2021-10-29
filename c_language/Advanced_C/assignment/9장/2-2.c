#include <stdio.h>

int passengern(int n){      
    if(n < 5){      // �Ű�����, �� �°� ���� 5���� ������ -1 ��ȯ
        return -1;
    }
    else{           // �̿��� ��� 0 ��ȯ
        return 0;
    }
}

int changeseat(int *ar){
    int check, empty; // �ش� ���ڰ� �ִ��� ������ üũ, ����ִ� ���� ������ ���� ����
    int *p; // ������ ���� ����
    for(int i = 1; i < 22; i++){    // ���ڰ� 1 ~ 21���������Ƿ� ��� üũ�ϱ����� �ݺ�
        check = 1;      //  üũ ������ �ϴ� 1�� ����
        for(p = ar; *p != 0; p++){  // 0�� �ƴ� ������ 
            if(i == *p){    // ���� �ش� ���ڰ� �ִٸ�
                check = 0;  // üũ ������ 0���� �ٲٰ� �ݺ��� Ż��
                break;
            }
        }
        if(check){  // ���� �ش� ���ڰ� �����ٸ�
            empty = i;  // ����ִ� ���ڿ� �ش� ���� ����
            break;  // �ݺ��� Ż��
        }
    }
    return empty;   // ����ִ� ���� (�¼�) ��ȯ

}
int rebooking(int *ar){
    int *p_i, *p_j, *last_address;  // �ݺ����� ����� ������ ������ ���� ������ ������ �ּҸ� ������ ������ ���� ����
    int check_overlab_num;      // �ߺ��Ǵ��� üũ�� ���� ����
    for(p_i = ar; *p_i != 0; p_i++){    // 0�� �ƴҶ����� �ݺ�
        last_address = p_i;             // �ݺ� �ø��� ������ �ּҸ� �ʱ�ȭ
    }

    for(p_i = ar; p_i < last_address - 1; p_i++){   //  ������ �ּ� �ձ��� �ݺ�
        check_overlab_num = *p_i;   // üũ ������ �ش� ���ҷ� �ʱ�ȭ
        for(p_j = p_i + 1; *p_j != 0; p_j++){   // �ش� ���Һ��� �迭 ���������� �ݺ�
            if(check_overlab_num == *p_j){  // ���� �ߺ��� �ȴٸ�
                *p_j = changeseat(ar);  // ��ȯ�� ���ڸ��� �ߺ��Ǵ� ���ҿ� ����
            }
        }
    }
}


int main(){
    int n, arr[21] = { 0, };    // �°���, �¼� �迭�� ����, �¼� �迭�� ��� �������� �������� �˱����� ��� ���Ҹ� 0���� �ʱ�ȭ
    int *p_n = &n, *p_arr;      // ������ ���� ����

    scanf("%d", p_n);   // �°� �� �Է�

    for(p_arr = arr; p_arr < arr + n; p_arr++){ // �°� �� ��ŭ �ݺ�
        scanf("%d", p_arr); // �¼� ��ȣ �Է�
    }
    if(passengern(n) == -1){    // ���� 5�� ���� ���ٸ�
        printf("-1");   // -1����ϰ� ���α׷� ����
        return 0;
    }
    else{   //�̿��� ��� 0 ���
        printf("0\n");
    }
    rebooking(arr); // �ߺ��� ã�� �¼� ��ȣ�� �ٲٴ� �Լ� ȣ��

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        printf("%d ", *p_arr);          // ��� ���
    }
    
    return 0;
}