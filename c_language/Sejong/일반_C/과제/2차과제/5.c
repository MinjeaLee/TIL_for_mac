#include <stdio.h>

int main(){
    int a,b,c;              // ���ڸ� 10������ �Է¹޾ƾ� �ϹǷ� ���� �ڸ��� ������ ���� a, �����ڸ��� ������ ���� b�� ����
                            // ���� ���ڸ������� �ƴ����� �Ǵ��� ���� c����
    scanf("%c%c", &a,&b); // char������ �޾� �� �ڸ��� ���� �� �ְ� �ϰ� ���ڸ��� �Է��� ��� b�� \n�� ���� �ǰ� ��.
    if (b != '\n'){        // 1�� �ڸ� ���� �Է��ߴٸ� �߰������� ����c�� �Է� ���� �ʵ��� �ϰ�, ���� �ڸ��̻��� ���� �Է��ߴٸ� �Է¹ް� ��.
        scanf("%c", &c);
    }
                 
    if (b == '\n' || (c != '\n' && c != ' ')){       // b�� \n�� �Էµ� ��� �� ���ڸ��� �Էµɰ��
                                       // ���� c�� \n�� �ƴ� ���� ����ȴٸ� �� ��� ���� none��� �� �� �ְ���.
        printf("none");   // none�� ��µǰ� ��.
    }
    
    else if(a == '1' && (b == '0' || b == '1' || b == '2')){    // �� ������ ������ ��� 10,11,12�� ����Ǵ� ���λ糪 ���̻簡 ���⿡ ���ε��� ��µǰ� ��.
        switch(b){        // b�� ������ ��
            case '0':     // b�� 0�� ���
                printf("ten");  // ten ���2
                break;

            case '1':     // b�� 1�� ���
                printf("eleven");   // eleven
                break;

            case '2':    // b�� 2�� ���
                printf("twelve");   // twleve
                break;
            
        }

    }
    else if(a == '1'){  // 10,11,12������ �ٸ� �ʹ����� ���ڴ� ���̻�� ���⿡ ���λ縸 �ٲٱ����� switch�� ���
                        // ���� 20����� �� ���� ��� ���λ�� ���̻簡 ��Ģ������ ���������� �ʹ����� ��� �׷��� �ʱ⿡ �ٸ� �ʹ����� ���ڿ� ����
        switch(b){
            case '3':   // ���ڰ� 13
                printf("thir"); 
                break;

            case '4':   // ���ڰ� 14
                printf("four");
                break;

            case '5':   // ���ڰ� 15
                printf("fif");
                break;
            
            case '6':   // ���ڰ� 16
                printf("six");
                break;
            
            case '7':   // ���ڰ� 17
                printf("seven");
                break;

            case '8':   // ���ڰ� 18
                printf("eigh");
                break;

            case '9':   // ���ڰ� 19
                printf("nine");
                break;
        }
        printf("teen"); // 10,11,12 �� ������ �ʹ����� ������ ���� ���̻��� teen�� ���
    }
    else{
        switch(a){      // �׿��� ��� ���̻�� ���λ簡 ��Ģ���̹Ƿ� ���� switch���� ���
            case '2':   // 20���� ���̻�
                printf("twenty");
                break;
            
            case '3':   // 30���� ���̻�
                printf("thirty");
                break;

            case '4':   // 40���� ���̻�
                printf("forty");
                break;
            
            case '5':   // 50���� ���̻�
                printf("fifty");
                break;
            case '6':   // 60���� ���̻�
                printf("sixty");
                break;
            
            case '7':   // 70���� ���̻�
                printf("seventy");
                break;

            case '8':   // 80���� ���̻�
                printf("eighty");
                break;

            case '9':   // 90���� ���̻�
                printf("ninety");
                break;
        }
        switch(b){  
            case '0':   // ���� �ڸ� 0�� ���̻�, 0�� ���λ簡 ����.
                break;
            
            case '1':   // ���� �ڸ� 1�� ���̻�
                printf("-one");
                break;
                
            case '2':   // ���� �ڸ� 2�� ���̻�
                printf("-two");
                break;
                
            case '3':   // ���� �ڸ� 3�� ���λ�
                printf("-three");
                break;
                
            case '4':   // ���� �ڸ� 4�� ���λ�
                printf("-four");
                break;
                
            case '5':   // ���� �ڸ� 5�� ���λ�
                printf("-five");
                break;
                
            case '6':   // ���� �ڸ� 6�� ���λ�
                printf("-six");
                break;
                
            case '7':   // ���� �ڸ� 7�� ���λ�
                printf("-seven");
                break;

            case '8':   // ���� �ڸ� 8�� ���λ�
                printf("-eight");
                break;
                
            case '9':   // ���� �ڸ� 9�� ���λ�
                printf("-nine");
                break;
        }

    }

    return 0;
}