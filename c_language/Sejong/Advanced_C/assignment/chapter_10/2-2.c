#include <stdio.h>
#include <string.h>

int main(){
    char word[10][100], string[1024], *p, tmp[100];
    // �ܾ ������ ���� �迭, �Է¹��� ���ڿ�, ������, �ܾ ������ �� ���� ���ڿ� ����
    int word_index_1d = 0, word_index_2d = 0, num_word = 0;
    // ���� �迭�� �ε����� ǥ���� ����, �ܾ��� ������ ǥ���� ����
    
    gets(string);   // ���ڿ� �Է�

    for(p = string; *p != '\0'; p++){   // ���ڿ��� ���� ������ �ݺ�
        if(*p != ' '){  // ������ �ƴ϶��
            word[word_index_1d][word_index_2d] = *p; // ���� �迭�� ����
            word_index_2d++;    // ������ �̵�
        }
        else{ // �����̸�
            word[word_index_1d][word_index_2d] = '\0'; // �ܾ��� ���� �ι��� ����
            num_word++;                                 // �ܾ��� ���� ++
            word_index_1d++;                            // ������ �̵�
            word_index_2d = 0;                          // ó������ �̵�
        }
    }
    num_word++;         // ������ �ܾ�� ++�� �ȵǱ⿡ ++

    for(int i = 0; i < num_word; i++){  // �ܾ� ���
        puts(word[i]);
    }

    for(int i = 0; i < num_word - 1; i++){       // �������� ��� ���ʴ�� �� �ܾ� ������ �ܾ�� - 1�� ����
        for(int j = 0; j < num_word - 1 - i; j++){
            if(word[j][0] > word[j + 1][0]){        //  ù ���ĺ� �� �ƽ�Ű�ڵ尡 ū���� �ڷ� ������ ����
                strcpy(tmp, word[j]);       // ���Ұ���
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tmp);
            }
        }
    }

    for(int i = 0; i < num_word; i++){      // �ܾ� ���
        puts(word[i]);
    }


    return 0;
}