#include <stdio.h>
#include <string.h>

int main(){
    char word[50][50], string[101], *p, cmp[101];
    // ������ �ܾ ������ �迭, �Է¹��� ���ڿ�, ������ , �񱳴ܾ� �迭 ����
    int total = 0, word_index_1d = 0, word_index_2d = 0;// �� ����, ���� �迭�� �ε����� ǥ���� ����

    gets(string);   // ���ڿ� �Է�
    gets(cmp);      // �� �ܾ� �Է�

    for(p = string; *p != '\0'; p++){   // ���ڿ��� ���� ������ �ݺ�
        if(*p != ' ' && *p != '.'){ // ������ �ƴϰ� . �� �ƴ϶��
            word[word_index_1d][word_index_2d] = *p;// ���� �迭�� ����
            word_index_2d++;  // ������ �̵�
        }
        else{ // �����̰ų� . �̶��
            word[word_index_1d][word_index_2d] = '\0';// �ܾ��� ���� �ι��� ����
            word_index_1d++;// ������ �̵�
            word_index_2d = 0; // ó������ �̵�
        }
    }

    for(int i = 0; i < word_index_1d + 1; i++){ // �ܾ��� ���� ��ŭ �ݺ�, ���ڿ� �������� �����̳� .�� �ƴѰ�� ������ -1 �Ǳ⶧���� +1 ����
        if(strcmp(word[i], cmp) == 0){  // �ܾ �������
            total++; // ���� ���� ++
        }
    }
    
    printf("%d", total);        // ��� ���

    return 0;
}