#include <stdio.h>
#include <limits.h> // ������ �ּҰ�, �ִ밪�� ����ϱ� ���� limits ��������� ��.

int main(){
    int max_x[20], i, j, n, max[7], min[7], max_num =INT_MIN, min_num = INT_MAX;
    // ���� �����ϴ� �迭(�̴� max�� �����ϴµ� �ٽ� ����.) for�� ���� i,j ��Է��� �� �Է¹޴� ����n, �� �ܰ��� max�� min�� �����ϴ� �迭, max�� ������ �ּҰ�����, min�� ������ �ִ밪���� ����.
    int count = 0, min_x[20];
    // �� �ܰ��� �迭�� ���� count�� ����, 0���� ����, min�� �����ϴµ� ���� �迭 ����
    scanf("%d", &n); // ����n �Է�
    for(i = 0; i < n; i++){
        scanf("%d", &max_x[i]); // ���� �Է¹ް� �̸� ���ʴ�ξ� max_x�� ���� 
        min_x[i] = max_x[i]; // �Ȱ��� min_x�� ����
    }
    for(i = 0; i < n; i++){
        printf(" %d", max_x[n - 1 - i]); // max_x�� ���� �Ųٷ� ���
    }
    printf("\n"); // �ٹٲ�
    
    while(count != 1){ // ������ ���� 1�� ������ ����.
        count = 0; // ������ ���� 0���� �ʱ�ȭ
        for(i = 0; i < n; i += 3){ // n���� i�� 3�� �����ϸ�
            count++;    // ������ ���� 1�� �ø�
            if(n % 3 == 0){ // n�� 3�� ������
                for(j = 0; j < 3; j++){ // 3���� ������ j�� �����ϸ�
                    if(max_num < max_x[i+j]){ // max_x�� i+j��° ���� max_num���� ũ�ٸ�
                        max_num = max_x[i+j]; // �̸� max_num���� ����
                    }
                    if(min_num > min_x[i+j]){ // min_x�� i+j��° ���� min_num���� ũ�ٸ�
                        min_num = min_x[i+j]; // �̸� min_num���� ����
                    }
                }
            }
            else{ // n�� 3�� ����� �ƴ϶��
                if(i == n - (n % 3)){   // ������ max�� min�� �Ǻ��Ҷ� i�� n - n % 3�̾�� ��, ���� ������ ��°�϶�
                    for(j = 0; j < n % 3; j++){  // �������� ����ŭ �ݺ�
                        if(max_num < max_x[i+j]){// max_x�� i+j��° ���� max_num���� ũ�ٸ�
                            max_num = max_x[i+j];// �̸� max_num���� ����
                        }
                        if(min_num > min_x[i+j]){// min_x�� i+j��° ���� min_num���� ũ�ٸ�
                            min_num = min_x[i+j];// �̸� min_num���� ����
                        }
                    }
                }
                else{                       // �� �̿��� ���
                    for(j = 0; j < 3; j++){ // 3���� ������ j�� �����ϸ�
                        if(max_num < max_x[i+j]){// max_x�� i+j��° ���� max_num���� ũ�ٸ�
                            max_num = max_x[i+j];// �̸� max_num���� ����
                        }
                        if(min_num > min_x[i+j]){// min_x�� i+j��° ���� min_num���� ũ�ٸ�
                            min_num = min_x[i+j];// �̸� min_num���� ����
                        }
                    }

                }
            }
            max[count - 1] = max_num;   // ī������ -1 ��°�� max�迭�� �� ��°�� �ִ��� ����
            min[count - 1] = min_num;   // ī������ -1 ��°�� min�迭�� �� ��°�� �ּҰ��� ����
            max_num = INT_MIN;  // �ٽ� max�� ������ �ּҰ�����, min�� ������ �ִ밪���� ����.
            min_num = INT_MAX;
        }
        for(i = 0; i < count; i++){ // ������ ����ŭ �ݺ�
            printf(" %d", max[i]);  // max�� ���Ҹ� ������� ���
            max_x[i] = max[i];  // �� ���Ҹ� �ٽ� �Ǻ��ϱ� ���� max_x�� max�� ���Ҹ� ������� ����
        }   
        printf("\n");   // �ٹٲ�
        for(i = 0; i < count; i++){ // ������ ����ŭ �ݺ�
            printf(" %d", min[i]);  // min�� ���Ҹ� ������� ���
            min_x[i] = min[i];  // �� ���Ҹ� �ٽ� �Ǻ��ϱ� ���� min_x�� min�� ���Ҹ� ������� ����
        }
        printf("\n"); // �ٹٲ�
        n = count;  // n�� �ٽ� ī��Ʈ�� ����
    }
    return 0;
}