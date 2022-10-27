#include <stdio.h>

int main(){
    int num, a,b,c; // 입력받을 숫자를 저장할 변수 num과 십의자리, 일의자리를 저장할 변수를 각각 a,b 백의자리와 그이상의 수가 입력되는지를 판단할 변수 c를 선언
    scanf("%d", &num); // 수 입력
    a = num / 10 % 10; // 십의자리 저장
    b = num % 10;   // 일의 자리 저장
    c = num / 100;  // 백의 자리, 그이상의 수를 저장
    if (a == 0 || c != 0){  // 만약 십의 자리가 0이거나(즉 한자리 수가 입력 된경우) 백의 자리가 0이 아닌 경우(즉 백의자리 이상의 수가 입력된경우)
        printf("none"); // none 출력
    }
    else if(a == 1 && (b == 0 || b == 1 || b == 2)){
        switch(b){        // b를 변수로 함
            case 0:     // b가 0일 경우
                printf("ten");  // ten 출력2
                break;

            case 1:     // b가 1일 경우
                printf("eleven");   // eleven
                break;

            case 2:    // b가 2일 경우
                printf("twelve");   // twleve
                break;
            
        }
    }
    else if(a == 1){  // 10,11,12제외한 다른 십번대의 숫자는 접미사는 같기에 접두사만 바꾸기위한 switch문 사용
                        // 또한 20번대와 그 외의 경우 접두사와 접미사가 규칙적으로 동일하지만 십번대의 경우 그렇지 않기에 다른 십번대의 숫자와 구별
        switch(b){
            case 3:   // 숫자가 13
                printf("thir"); 
                break;

            case 4:   // 숫자가 14
                printf("four");
                break;

            case 5 :   // 숫자가 15
                printf("fif");
                break;
            
            case 6 :   // 숫자가 16
                printf("six");
                break;
            
            case 7 :   // 숫자가 17
                printf("seven");
                break;

            case 8 :   // 숫자가 18
                printf("eigh");
                break;

            case 9 :   // 숫자가 19
                printf("nine");
                break;
        }
        printf("teen"); // 10,11,12 를 제외한 십번대의 숫자의 공통 접미사인 teen을 출력
    }
    else{
        switch(a){      // 그외의 경우 접미사와 접두사가 규칙적이므로 각각 switch문을 사용
            case 2:   // 20번대 접미사
                printf("twenty");
                break;
            
            case 3:   // 30번대 접미사
                printf("thirty");
                break;

            case 4:   // 40번대 접미사
                printf("forty");
                break;
            
            case 5:   // 50번대 접미사
                printf("fifty");
                break;
            case 6:   // 60번대 접미사
                printf("sixty");
                break;
            
            case 7:   // 70번대 접미사
                printf("seventy");
                break;

            case 8:   // 80번대 접미사
                printf("eighty");
                break;

            case 9:   // 90번대 접미사
                printf("ninety");
                break;
        }
        switch(b){  
            case 0:   // 일의 자리 0의 접미사, 0은 접두사가 없음.
                break;
            
            case 1:   // 일의 자리 1의 접미사
                printf("-one");
                break;
                
            case 2:   // 일의 자리 2의 접미사
                printf("-two");
                break;
                
            case 3:   // 일의 자리 3의 접두사
                printf("-three");
                break;
                
            case 4:   // 일의 자리 4의 접두사
                printf("-four");
                break;
                
            case 5:   // 일의 자리 5의 접두사
                printf("-five");
                break;
                
            case 6:   // 일의 자리 6의 접두사
                printf("-six");
                break;
                
            case 7:   // 일의 자리 7의 접두사
                printf("-seven");
                break;

            case 8:   // 일의 자리 8의 접두사
                printf("-eight");
                break;
                
            case 9:   // 일의 자리 9의 접두사
                printf("-nine");
                break;
        }

    }
   
    return 0;
}