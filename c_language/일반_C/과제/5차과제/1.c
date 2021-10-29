#include <stdio.h>
//restore github

int num_digit(int n){       // num_digit 함수 정의
    int len = 0;            // 결과값 변수 선언
    do{
        len++;              // len++
        n /= 10;            // n을 10씩 나눔
    }while(n != 0);         // n이 0이 아닐때까지 반복
    return len;             // 결과값 반환
}

int convert_top(int n, int len){    // convert_top함수 정의
    int pow = 1, convert;           // 10의 제곱을 저장할 변수, 추출한 값을 저장할 변수 선언
    if(len == 1){                   // len이 1이 될떄에는 밑의 경우에 들어갈 경우 0이 되므로 따로 지정
        pow = 1;                    
    }
    else{   
        for(int i = 0; i < len; i++){   // 길이민큼 반복       
            pow *= 10;                  // 10 ^ (len)만큼 값을 pow에 저장하게 함
        }
        pow /= 100;                     // 두 숫자만 추출해야하므로 / 100을 해줌
    }
    convert = n / pow;                  // 추출한 값은 n / pow로 저장
    if('a' <= convert && convert <= 'z' || 'A' <= convert && convert <= 'Z'){       // 추출한 값이 알파벳 범위일 경우
        printf("%c", convert);                                                      // %c로 변환하여 출력
    }
    else{                                                                           // 그 이외의 경우
        printf("*");                                                                // 별 출력
    }
    n = n - (convert * pow);                                                        // n을 n에 출력한 값에 pow를 곱한 값을 뺴게 되면 추출한 두 숫자를 빼어 저장
    if(len - 2 > 0){                    //  len - 2한 값이 0이상일 경우 
        return n;                       // 나머지 숫자 반환
    }
    else{                               // 그 외의 경우
        return 0;                       // 0 반환
    }
}

int convert_bottom(int n){              // convert_bottom함수 정의
    int convert;                        // 추출할 숫자 저장 변수 선언
    convert = n % 100;                  // convert에 n % 100값을 저장
    n /= 100;                           // n의 값을 100을 나눈값 저장
    if('a' <= convert && convert <= 'z' || 'A' <= convert && convert <= 'Z'){ // 추출한 값이 알파벳의 범위라면
        printf("%c", convert);                                                // %c로 변환하여 출력
    }
    else{
        printf("*");                                                          // 그 외의 경우 *별출력
    }
    if(num_digit(n) > 0){                                                     // 숫자의 길이가 0보다 클 경우
        return n;                                                             // 나머지 숫자 출력
    }
    else{                                                                     // 그 외의 경우 
        return 0;                                                             // 0출력
    }
}

int main(){
    int num, len;                                                             // 입력 받을 숫자 저장 변수, 숫자의 길이 저장할 변수 선언
    scanf("%d", &num);                      // 숫자 입력 
    len = num_digit(num);                   // len에 num_digit함수 이용하여 저장
    if(len % 2 != 0){                       // 길이가 짝수가 아닐경우
        while(len >= 1){                    // len이 1이상일 동안
            num = convert_top(num, len);    // num을 convert_top의 결과값을 저장
            len -= 2;                       // len 을 -2 씩 해줌
        }
    }
    else{                                   // 그외의 경루
        while(len > 0){                     // len이 0보다 클때 동안
            num = convert_bottom(num);      // num을 convert_bottom의 결과값을 저장
            len -= 2;                       // len 을 -2 씩 해줌
        }
    }

    return 0;
}