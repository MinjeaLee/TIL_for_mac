#include <stdio.h>

int main(){
    int a,b,c;              // 두자리 10진수를 입력받아야 하므로 십의 자리를 저자할 변수 a, 일의자리를 저장할 변수 b를 선언
                            // 또한 두자리수인지 아닌지를 판단할 변수 c선언
    scanf("%c%c", &a,&b); // char형으로 받아 한 자리씩 받을 수 있게 하고 한자리를 입력할 경우 b에 \n가 저장 되게 함.
    if (b != '\n'){        // 1의 자리 수를 입력했다면 추가적으로 변수c를 입력 받지 않도록 하고, 백의 자리이상의 수를 입력했다면 입력받게 함.
        scanf("%c", &c);
    }
                 
    if (b == '\n' || (c != '\n' && c != ' ')){       // b에 \n가 입력될 경우 즉 한자리만 입력될경우
                                       // 또한 c에 \n가 아닌 것이 저장된다면 이 경우 또한 none출력 될 수 있게함.
        printf("none");   // none이 출력되게 함.
    }
    
    else if(a == '1' && (b == '0' || b == '1' || b == '2')){    // 십 번대의 숫자의 경우 10,11,12가 공통되는 접두사나 접미사가 없기에 따로따로 출력되게 함.
        switch(b){        // b를 변수로 함
            case '0':     // b가 0일 경우
                printf("ten");  // ten 출력2
                break;

            case '1':     // b가 1일 경우
                printf("eleven");   // eleven
                break;

            case '2':    // b가 2일 경우
                printf("twelve");   // twleve
                break;
            
        }

    }
    else if(a == '1'){  // 10,11,12제외한 다른 십번대의 숫자는 접미사는 같기에 접두사만 바꾸기위한 switch문 사용
                        // 또한 20번대와 그 외의 경우 접두사와 접미사가 규칙적으로 동일하지만 십번대의 경우 그렇지 않기에 다른 십번대의 숫자와 구별
        switch(b){
            case '3':   // 숫자가 13
                printf("thir"); 
                break;

            case '4':   // 숫자가 14
                printf("four");
                break;

            case '5':   // 숫자가 15
                printf("fif");
                break;
            
            case '6':   // 숫자가 16
                printf("six");
                break;
            
            case '7':   // 숫자가 17
                printf("seven");
                break;

            case '8':   // 숫자가 18
                printf("eigh");
                break;

            case '9':   // 숫자가 19
                printf("nine");
                break;
        }
        printf("teen"); // 10,11,12 를 제외한 십번대의 숫자의 공통 접미사인 teen을 출력
    }
    else{
        switch(a){      // 그외의 경우 접미사와 접두사가 규칙적이므로 각각 switch문을 사용
            case '2':   // 20번대 접미사
                printf("twenty");
                break;
            
            case '3':   // 30번대 접미사
                printf("thirty");
                break;

            case '4':   // 40번대 접미사
                printf("forty");
                break;
            
            case '5':   // 50번대 접미사
                printf("fifty");
                break;
            case '6':   // 60번대 접미사
                printf("sixty");
                break;
            
            case '7':   // 70번대 접미사
                printf("seventy");
                break;

            case '8':   // 80번대 접미사
                printf("eighty");
                break;

            case '9':   // 90번대 접미사
                printf("ninety");
                break;
        }
        switch(b){  
            case '0':   // 일의 자리 0의 접미사, 0은 접두사가 없음.
                break;
            
            case '1':   // 일의 자리 1의 접미사
                printf("-one");
                break;
                
            case '2':   // 일의 자리 2의 접미사
                printf("-two");
                break;
                
            case '3':   // 일의 자리 3의 접두사
                printf("-three");
                break;
                
            case '4':   // 일의 자리 4의 접두사
                printf("-four");
                break;
                
            case '5':   // 일의 자리 5의 접두사
                printf("-five");
                break;
                
            case '6':   // 일의 자리 6의 접두사
                printf("-six");
                break;
                
            case '7':   // 일의 자리 7의 접두사
                printf("-seven");
                break;

            case '8':   // 일의 자리 8의 접두사
                printf("-eight");
                break;
                
            case '9':   // 일의 자리 9의 접두사
                printf("-nine");
                break;
        }

    }

    return 0;
}