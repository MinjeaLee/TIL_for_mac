#include <stdio.h>

int main(){
    int n, arr[21];     // �°����� �¼� �迭 ����
    int *p_n = &n, *p_arr, *p_i, *p_j;  // ������ ���� ����
    int count_overlap_arr = 0, count_overlap_num, overlap_num; // �迭�� �ߺ��� �ִ��� �������� ����, ������ ���ڰ� ��� �ߺ��Ǵ� ��, � ���ڰ� �ߺ��Ǵ��� üũ�� ���� ����

    scanf("%d", p_n);   // �°� �� �Է�

    for(p_arr = arr; p_arr < arr + n; p_arr++){ // �°� �� ��ŭ �ݺ�
        scanf("%d", p_arr); // �¼� ��ȣ �Է�
    }
    if(n < 5){  // �� ���� 5���� �۴ٸ�
        printf("-1");   // -1 ��� �ϰ� ���α׷� ����
        return 0;
    }

    for(p_i = arr; p_i < arr + n; p_i++){   // �°� �� ��ŭ �ݺ�
        overlap_num = *p_i;         // üũ�� ���� ����
        count_overlap_num = 0;  // ī��Ʈ�� 0���� �ʱ�ȭ
        for(p_j = arr; p_j < arr + n; p_j++){   // �°� �� ��ŭ �ݺ�
            if(overlap_num == *p_j){    // ���� ���ٸ�
                count_overlap_num++;    // ī��Ʈ�� +1 ���ְ�
                *p_j = -1;              // �ߺ� üũ�� ���� ���� -1�� ��ȯ
            }
        }
        if(count_overlap_num > 1 && overlap_num != -1){ // üũ�� ���ڰ� 0�� �ƴϰ� 1���� Ŭ��(üũ�ҋ� ������ +1�� �Ǳ� ����)
            count_overlap_arr++;    // �ߺ� ī��Ʈ +1
            printf("%d %d\n", overlap_num, count_overlap_num);  // ��� ���
        }
    }

    if(count_overlap_arr == 0){         // �迭�� �ߺ��� ���ٸ�
        printf("0");    // 0 ���
    }
    return 0;
}