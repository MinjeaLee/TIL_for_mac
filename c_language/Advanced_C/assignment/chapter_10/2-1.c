#include <stdio.h>
#include <string.h>

int main(){
    char word[101], tmp;    // ���ڿ�, tmp ����

    scanf("%s", word);      // ���ڿ� �Է�

    // �������� ���
    for(int i = 0; i < strlen(word) - 1; i++){
        // ���ʴ�� �� ���� ������ len - 1�� ����
        for(int j = 0; j < strlen(word) - 1 - i; j++){
            if(word[j] > word[j + 1]){ // �ƽ�Ű�ڵ尡 ū���� �ڷ� ������ ����
                tmp = word[j];      // �� ���� ���� ����
                word[j] = word[j + 1];
                word[j + 1] = tmp;
            }
        }
    }

    printf("%s", word);

    return 0;
}