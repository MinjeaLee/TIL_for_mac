#include <stdio.h>
#include <string.h>

typedef struct st{
    char name[10]; //�л��̸�
    char book[6][20]; //�������� �� å �̸� (��) History Politics
    int score[6]; //�� å�� ���� �������� ���� (��) 60 40
    int cnt, pcnt; //�������� �� å�� �Ǽ�, ����� å�� �Ǽ�
} st_;

int main(){
    st_ list[100];
    int n;
    char tmp[20];
    int count, pass;
    double pct;

    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++){
        scanf("%s", &list[i].name);
        getchar();
        count = 0;
        while(1){
            scanf("%s", &list[i].book[count]);
            if(strcmp(list[i].book[count], "0") == 0){
                break;
            }
            else{
                scanf("%d", &list[i].score[count]);
                getchar();
                count++;
            }
        }
        list[i].cnt = count;
        pass = 0;
        for(int j = 0; j < count; j++){
            if(list[i].score[j] >= 50){
                pass++;
            }
        }
        list[i].pcnt = pass;
        pct = (list[i].pcnt) * 20;

        printf("%s %.0lf%%\n", list[i].name, pct);

    }


    return 0;
}

