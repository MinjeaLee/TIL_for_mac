#include <stdio.h>

int main(){
    int x[100], y[100], result[200], num ,i = 0, x_n, y_n , count = 0, check = 0, j, tmp; // a����, b����, ������ ũ�⸦ ���� 100, 100, 200���� �����ϰ�, �Է¹��� ����, for, while�� ����, �� ������ len, �������� len, �ߺ� üũ ����, �ӽ� ���� ���� ����
    while(1){               // ���� ����
        scanf("%d", &num);  // ���� �Է�
        if(num < 0){        // �� �����
            break;          // break
        }
        x[i] = num;         // a���տ�����
        i++;                // i++  
    }
    x_n = i;                // ���� i�� a������ len���� ����
    i = 0;                  // i �ʱ�ȭ
    while(1){               // ���� ����
        scanf("%d", &num);  // ���� �Է�
        if(num < 0){        // �� �����
            break;          // break
        }
        y[i] = num;         // B���տ�����
        i++;                // i++ 
    } 
    y_n = i;                // ���� i�� B������ len���� ����
    for(i = 0; i < x_n; i++){               // a���� len��ŭ �ݺ�
        check = 0;                          // �ߺ� üũ ������ 0����
        for(j = 0; j < count; j++){         // �������� len ��ŭ �ݺ��ϸ�
            if(x[i] == result[j]){          // �ߺ��Ǵ� ���� �ִ��� üũ
                check = 1;                  // �ߺ��� �ִٸ� check������ 1�� �����ϰ� break
                break;
            }
        }
        if(check == 0){                     // �ߺ��� ���ٸ�
            result[count] = x[i];           // result�� ���ʴ�� ����
            count++;                        // �������� len++
        }
    }
    for(i = 0; i < y_n; i++){               // b���� len��ŭ �ݺ�
        check = 0;                          // �ߺ� üũ ������ 0����
        for(j = 0; j < count; j++){         // �������� len ��ŭ �ݺ��ϸ�
            if(y[i] == result[j]){          // �ߺ��Ǵ� ���� �ִ��� üũ
                check = 1;                  // �ߺ��� �ִٸ� check������ 1�� �����ϰ� break
                break;
            }
        }
        if(check == 0){                     // �ߺ��� ���ٸ�
            result[count] = y[i];           // result�� ���ʴ�� ����
            count++;                        // �������� len++
        }
    }
    for(i = 0; i < count - 1; i++){         // ���� ���� �˰��� �ε����� 0���� len - 1���� ����
        for(j = i + 1; j < count; j++){     //  i + 1���� ������ �������� ����
            if(result[i] > result[j]){      //  j ���� i�� �� ū���� �ִٸ�
                tmp = result[j];            // ����
                result[j] = result[i];
                result[i] = tmp;
            }
        }
    }
    for(i = 0; i < count; i++){             // ���ʴ�� ���
        printf(" %d", result[i]);
    }

    return 0;    
}