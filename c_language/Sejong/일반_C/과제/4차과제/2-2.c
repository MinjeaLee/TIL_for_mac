#include <stdio.h>

int main(){
    char x[50], y[50], a, v_x, v_y, tmp; // 단어를 담을 배열 x,y 문자 입력 변수, 각 배열에서 모음을 담을 변수, 임시 저장 변수 선언
    int i = 0, x_count = 0, y_count = 0, v_x_n = 0, v_y_n = 0, j, k = 0, check_x = 0, check_y = 0, min; // for, while 변수, x,y단어 길이 저장 변수, 모음의 인덱스 번호, 모음을 체크할 변수 선언, 단어의 최솟값저장 변수 선언
    while(1){               // 무한루프
        scanf("%c", &a);    // 문자 입력
        if(a == '*'){       // *이면 break
            break;
        }
        x[i] = a;   // 단어 저장
        i++;        // i++
    }
    x_count = i;    // 최종 i를 x의 단어 길이로
    getchar();      // \n제거
    i = 0;          // i  초기화
    while(1){          // 무한루프
        scanf("%c", &a);     // 문자 입력
        if(a == '*'){       // *이면 break
            break;
        }
        y[i] = a;           // 단어 저장
        i++;                // i++
    }
    y_count = i;        // 최종 i를 y의 단어 길이로
    if(x_count > y_count){     // x단어 길이가 클때 
        min = y_count;         // 최솟값을 y단어 길이
    }
    else{                       // x단어 길이가 클때
        min = x_count;          // 최솟값을 y단어 길이
    }
    while(k < min){              // 최솟값 만큼 반복
        k++;                     // k++
        for(i = v_x_n; i < x_count; i++){                       // x단어 길이만큼 반복, 모음 발견 이후 그 모음 뒤ㅔ 서부터 시작 할 수 있도록 i를 v_x_n으로 지정
            if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u'){        // 모음일때
                v_x = x[i];         // 그 모음을 v_x에 저장
                v_x_n = i + 1;      // v_x_n을 i + 1로 저장
                check_x = 1;        // 모음을 발견하였다고 cheak를 1로
                break;              // break
            }
        }
        for(j = v_y_n; j < y_count; j++){                       // y단어 길이만큼 반복, 모음 발견 이후 그 모음 뒤ㅔ 서부터 시작 할 수 있도록 i를 v_y_n으로 지정
            if(y[j] == 'a' || y[j] == 'e' || y[j] == 'i' || y[j] == 'o' || y[j] == 'u'){        // 모음일때
                v_y = y[j];         // 그 모음을 v_y에 저장
                v_y_n = j + 1;      // v_y_n을 i + 1로 저장
                check_y = 1;        // 모음을 발견하였다고 cheak를 1로
                break;              // break
            }
        }
        if(check_x == 1 && check_y == 1){       // 두 단어가 모음을 발견했을 때만 스왑하도록
            tmp = v_x;                          // 스왑
            v_x = v_y;
            v_y = tmp;
            x[v_x_n - 1] = v_x;                 // +1 로 저장 하였으므로 -1값으로 저장
            y[v_y_n - 1] = v_y;                 // +1 로 저장 하였으므로 -1값으로 저장
            check_x = 0;                        
            check_y =0;                         // cheak를 0으로 초기화
        }
    }
    for(i = 0; i < x_count; i++){               // 단어 출력
        printf("%c", x[i]);
    }
    printf("*\n");                              // 별출력 줄바꿈
    for(i = 0; i < y_count; i++){               // 단어 출려   
        printf("%c", y[i]);
    }
    printf("*\n");                              // 별출력 줄바꿈

    return 0;
}