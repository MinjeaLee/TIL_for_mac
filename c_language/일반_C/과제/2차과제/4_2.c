#include <stdio.h>

int main(){
    int num;
    // 얼마큼 증가할 것인지에 대한 숫자를 입력받을 변수 num 선언
    char result, s;
    // 입력한 문자를 저장할 변수 s와 s에 증가한 결과 문자를 저장할 변수 result를 선언
    scanf("%c %d", &s, &num);
    // 초기 문자와 증가시킬 숫자입력
    num = num % 26;
    // 증가할 숫자를 mod 26을 하여 저장. 알파벳 개수가 26개이기 떄문.
    if('a'<= s && s <= 'z'){
        // 만약 초기문자가 알파벳이라면
        result = s + num;
        // 결과값에 초기 문자에 저장한 더할 숫자를 더함.
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
        // 알파벳이 아닌경우 더하지 않고 그대로 결과에 저장.
        result = s;
    }
    
    printf("%c", result);
    // 결과값 출력
    
    return 0;
}