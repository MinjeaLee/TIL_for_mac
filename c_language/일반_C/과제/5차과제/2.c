#include <stdio.h>
//restore github

int SumMultiple(int Start, int End, int X);     // SumMultiple 함수 선언

int gcd(int x, int y){                          // 요구사항 3)을 보게 되면 최소공배수로 푸는게 간단하므로 m,n의 최소공배수를 
//구해야한다. 최소공배수는 두 수의 곱 / 두 수의 최대공약수 이므로 최대 공약수를 구할 필요가 있다. 최대공약수는 유클리드호제법을
// 이용해서 풀기위해 함수명을 gcd와 int인자 x, y로 한 함수를 선언하였다.
    int tmp;                        // 스왑을 하기위한 정수 선언
    if(y == 0){                     // 나누는 수가 0이면 오류가 나므로 바로 1을 반환하도록 함.
        return 1;
    }
    if(x < y){                      // x가 더 큰 수가 들어올 수 있도록 하기위해 x가 y보다 작다면
        tmp = x;                    // x, y를 서로 바꿔준다.
        x = y;
        y = tmp;
    }
    if(x % y == 0){                 // 나누었을 때 나머지가 0이면 두 수의 최대 공약수는 제수가 되므로 제수를 반환하도록 함.
        return y;
    }
    else{                           // 피제수를 제수로 나누어 그 나머지를 제수로 이전 계산에서 제수였던 것을 피제수로 하여 나머지가 0일때 까지 다시 gcd를 호출하도록 함.
        return gcd(y, x % y);
    }
}

int main(){
    int s, e, n, m;                 // s,e,n,m 선언
    int n1, n2, n3, n4, n5, n6;     // 각 줄에 출력될 결과값을 저장할 변수 선언
    scanf("%d %d %d %d", &s, &e, &n, &m);       // s,e,n,m 입력

    n1 = SumMultiple(s, e, n);      //  s 이상 e 미만의 정수 중 n의 배수의 합
    n2 = SumMultiple(s, e, m);      //  s 이상 e 미만의 정수 중 m의 배수의 합
    n3 = SumMultiple(s, e, n * m / gcd(n, m));      // n배수 이면서 m의 배수는 n,m의 공배수이므로 SumMultiple에 s, e, n과 m의 최소공배수를 인자로 주어 최소공배수의 배수의 합을 도출하게 함.
    n4 = SumMultiple(s, e, n) + SumMultiple(s, e, m) - SumMultiple(s, e, n * m / gcd(n, m));   
    // s 이상 e 미만의 정수 중 n의 배수이거나 m의 배수인 수의 합은 s부터 e-1까지의 n의 배수와 m의 배수를 모두 더하면 공배수의 배수가 겹치므로 공배수의 배수의 합을 뺴줌. 
    n5 = SumMultiple(s, e, m) - SumMultiple(s, e, n * m / gcd(n, m));
    // s 이상 e 미만의 정수 중 m의 배수이면서 n의 배수가 아닌 수의 합은 s부터 e-1까지의 m의 배수의 합에서 m과 n의 최소공배수의 합을 뺴줌.
    n6 = SumMultiple(s, e, 1) - SumMultiple(s, e, n) - SumMultiple(s, e, m) + SumMultiple(s, e, n * m / gcd(n, m));
    // s 이상 e 미만의 정수 중 n의 배수도 m의 배수도 아닌 수의 합은 s부터 e-1까지의 합에서 n의 배수의 합과 m의 배수의 합을 뺴주면 최소공배수의 배수의 합이 중복되어 빼지게 되므로 더함.

    printf("%d\n%d\n%d\n%d\n%d\n%d", n1, n2, n3, n4, n5, n6); // 차례대로 출력
}

int SumMultiple(int Start, int End, int X){  // 함수 설명
    int result = 0;                                         // 결과값 저장할 변수 선언
    for(int i = Start; i < End; i++){                       // start부터 end-1까지 i 를 1씩 증가시키며
        if(i % X == 0){                                     //  i가 X의 배수이면
            result += i;                                    // result에 더함.
        }
    }
    return result;                                          // result 반환
}

