#include <stdio.h>

int main(){
    int n1, n2, i, num, j, count_c, tmp_c = 0, count_f;     // 숫자 두개 받는 변수(n1, n2), for문 사용 변수(i,j), 각각의 숫자의 약수 갯수저장 변수, 임시로 저장할 소수개수, 소인수 갯주 저장 변수들 선언
    int max_c = 1, max_n = n1, max_f = 1; // 최대 약수 개수, 최대약수 개수의 수 저장, 소인수 지수의 합의 최대값을 저장할 변수;
    scanf("%d %d", &n1, &n2);       // 수입력
    for(i = n1; i <= n2; i++){      // n1과 n2까지 1씩 증가
        num = i;                    // num을 i로 지정하여 num을 가공하여도 i는 불변하게함.
        count_c = 1;                // count_c는 i++마다 1로 초기화
        count_f = 0;                // count_f는 i++마다 0로 초기화
        for(j = 2; 2 <= num; j++){  // 소인수를 카운트하기 위해 2부터 num까지
            while(num % j == 0){    // num을 j로 나누었을 때 0일동안만 반복
                num = num / j;      // num을 j로 나누었을 때 몫을 num으로 재저장
                tmp_c += 1;         // 임시로 저장할 소수개수++
            }
            count_c *= (tmp_c + 1); // 약수의 개수에 소수개수에 +1 한 값을 곱함.
            count_f += tmp_c;       // 지수의 합에 소수 개수를 +
            tmp_c = 0;              // 임시소수개수 변수를 0으로 초기화
        }
        if (max_c < count_c){       // 최대 약수 개수, 그 때의 숫자, 그 숫자의 지수의 합을 최대인 것으로 저장.
            max_c = count_c;
            max_n = i;
            max_f = count_f;
        }
    }
    printf("%d %d %d", max_n, max_c, max_f);    // 결과 출력
    return 0;
}