#include <stdio.h>

int main(){
    int num;
    // ��ŭ ������ �������� ���� ���ڸ� �Է¹��� ���� num ����
    char result, s;
    // �Է��� ���ڸ� ������ ���� s�� s�� ������ ��� ���ڸ� ������ ���� result�� ����
    scanf("%c %d", &s, &num);
    // �ʱ� ���ڿ� ������ų �����Է�
    num = num % 26;
    // ������ ���ڸ� mod 26�� �Ͽ� ����. ���ĺ� ������ 26���̱� ����.
    if('a'<= s && s <= 'z'){
        // ���� �ʱ⹮�ڰ� ���ĺ��̶��
        result = s + num;
        // ������� �ʱ� ���ڿ� ������ ���� ���ڸ� ����.
        if (result > 'z'){
            num = result -  'z';
            result = 'a' + num - 1;
        }
    }
    else if('A' <= s && s <= 'Z'){
        result = s + num;
        if(result > 'Z'){
            num = result -  'Z';
            result = 'A' + num - 1;
        }
    }
    else{
        // ���ĺ��� �ƴѰ�� ������ �ʰ� �״�� ����� ����.
        result = s;
    }
    
    printf("%c", result);
    // ����� ���
    
    return 0;
}