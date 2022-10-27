#include <stdio.h>
//restore github

int multiple(int x, int y){         // multiple 함수 정의
    if(x % y == 0){                 // x 가 y의 배수이면
        return  1;                  // 1 반환
    }
    else{                           // 그렇지 않으면 
        return 0;                   // 0 반환
    }
}

int maximum(int x, int y){          // maximum함수 정의
    if(x > y){                      // x가 y보다 크면
        return x;                   // x 반환
    }
    else{                           // 그렇지 않으면
        return y;                   // y반환
    }
}

int digit_maximum(int x){           // digit_maximum 함수 정의
    int max = 0, num;               // max를 0으로 선언, 자릿수 확인할 변수 선언
    while(x != 0){                  // x가 0이 아닐때까지
        num = x % 10;               // num에 계속해서 1의 자리를 저장
        x /= 10;                    // x를 계속해서 /10
        max = maximum(max, num);    // max비교
    }
    return max;                     // max 반환
}

int main(){
    int n, m, k, max = 0, nmax = 0; // 정수 n, m, k와 배수일 경우의 max 배수가 아닐 경우의 max 선언
    scanf("%d %d %d", &n, &m, &k);  // 정수 입력
    for(int i = n; i <= m; i++){    // n부터 m까지 i가 1씩 증가하며
        if(multiple(i, k)){         // i가 k의 배수라면
            max = maximum(max, digit_maximum(i));   // i의 자릿수 최댓값과 기존 max의 최댓값을 비교하여 더 큰수를 max에 저장 
        }
        else{                       // 배수가 아니면 
            nmax = maximum(nmax, i % k);            // 기존의 nmax와 i를 k로 나눈 나머지중에서 최댓값을 nmax에 저장
        }
    }
    printf("%d", maximum(max, nmax));               // max와 nmax를 비교하여 더 큰수를 출력
    
    return 0;
}