#include <stdio.h>

int main(){
    int num, a,b,c; // �Է¹��� ���ڸ� ������ ���� num�� �����ڸ�, �����ڸ��� ������ ������ ���� a,b �����ڸ��� ���̻��� ���� �ԷµǴ����� �Ǵ��� ���� c�� ����
    scanf("%d", &num); // �� �Է�
    a = num / 10 % 10; // �����ڸ� ����
    b = num % 10;   // ���� �ڸ� ����
    c = num / 100;  // ���� �ڸ�, ���̻��� ���� ����
    if (a == 0 || c != 0){  // ���� ���� �ڸ��� 0�̰ų�(�� ���ڸ� ���� �Է� �Ȱ��) ���� �ڸ��� 0�� �ƴ� ���(�� �����ڸ� �̻��� ���� �ԷµȰ��)
        printf("none"); // none ���
    }
    else if(a == 1 && (b == 0 || b == 1 || b == 2)){
        switch(b){        // b�� ������ ��
            case 0:     // b�� 0�� ���
                printf("ten");  // ten ���2
                break;

            case 1:     // b�� 1�� ���
                printf("eleven");   // eleven
                break;

            case 2:    // b�� 2�� ���
                printf("twelve");   // twleve
                break;
            
        }
    }
    else if(a == 1){  // 10,11,12������ �ٸ� �ʹ����� ���ڴ� ���̻�� ���⿡ ���λ縸 �ٲٱ����� switch�� ���
                        // ���� 20����� �� ���� ��� ���λ�� ���̻簡 ��Ģ������ ���������� �ʹ����� ��� �׷��� �ʱ⿡ �ٸ� �ʹ����� ���ڿ� ����
        switch(b){
            case 3:   // ���ڰ� 13
                printf("thir"); 
                break;

            case 4:   // ���ڰ� 14
                printf("four");
                break;

            case 5 :   // ���ڰ� 15
                printf("fif");
                break;
            
            case 6 :   // ���ڰ� 16
                printf("six");
                break;
            
            case 7 :   // ���ڰ� 17
                printf("seven");
                break;

            case 8 :   // ���ڰ� 18
                printf("eigh");
                break;

            case 9 :   // ���ڰ� 19
                printf("nine");
                break;
        }
        printf("teen"); // 10,11,12 �� ������ �ʹ����� ������ ���� ���̻��� teen�� ���
    }
    else{
        switch(a){      // �׿��� ��� ���̻�� ���λ簡 ��Ģ���̹Ƿ� ���� switch���� ���
            case 2:   // 20���� ���̻�
                printf("twenty");
                break;
            
            case 3:   // 30���� ���̻�
                printf("thirty");
                break;

            case 4:   // 40���� ���̻�
                printf("forty");
                break;
            
            case 5:   // 50���� ���̻�
                printf("fifty");
                break;
            case 6:   // 60���� ���̻�
                printf("sixty");
                break;
            
            case 7:   // 70���� ���̻�
                printf("seventy");
                break;

            case 8:   // 80���� ���̻�
                printf("eighty");
                break;

            case 9:   // 90���� ���̻�
                printf("ninety");
                break;
        }
        switch(b){  
            case 0:   // ���� �ڸ� 0�� ���̻�, 0�� ���λ簡 ����.
                break;
            
            case 1:   // ���� �ڸ� 1�� ���̻�
                printf("-one");
                break;
                
            case 2:   // ���� �ڸ� 2�� ���̻�
                printf("-two");
                break;
                
            case 3:   // ���� �ڸ� 3�� ���λ�
                printf("-three");
                break;
                
            case 4:   // ���� �ڸ� 4�� ���λ�
                printf("-four");
                break;
                
            case 5:   // ���� �ڸ� 5�� ���λ�
                printf("-five");
                break;
                
            case 6:   // ���� �ڸ� 6�� ���λ�
                printf("-six");
                break;
                
            case 7:   // ���� �ڸ� 7�� ���λ�
                printf("-seven");
                break;

            case 8:   // ���� �ڸ� 8�� ���λ�
                printf("-eight");
                break;
                
            case 9:   // ���� �ڸ� 9�� ���λ�
                printf("-nine");
                break;
        }

    }
   
    return 0;
}