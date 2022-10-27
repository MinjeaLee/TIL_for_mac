#include <stdio.h>

int main(){
    int i, x[20], f, r, m, vs, tmp;     // for문 변수, 집합, F, R, M, 바꿀 때 이용할 변수, 임시 저장 변수
    for(i = 1; i <= 20; i++){           // 집합에 1부터 20의 수를 저장
        x[i -1] = i;
    }
    scanf("%d %d %d", &f, &r, &m);      // F, R, M 입력
    vs = x[r];                          // 초기 VS를 x[r]로 저장
    for(i = 0; i < m; i++){             // m 만큼 반복
        tmp = x[r - m + 1 + i];         // 임시 저장 변수를 x[r - m + 1 + i]로 저장
        x[r - m + 1 + i] = vs;          //  vs와 스왑
        vs = tmp;                       // vs를 x[r - m + 1 + i]으로 하여 다음 수행에서도 쓰일 수 있게 함
    }
    for(i = 0; i < 20; i++){            // 차례대로 출력
        printf("%d ", x[i]);
    }
    
    return 0;
}