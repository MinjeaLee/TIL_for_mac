#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int n = 100000;
int Limits[4] = {1, 100, 500, 1000};
int Limit = 1;
char mode[4][20] = {"deterministic1", "deterministic3", "randomized1", "randomized3"};

int *createArray() 
{
    srand(time(NULL)); // seed set

    int *A = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % n + 1; // 1 ~ n
    }
    return A;
}

int findIndexOfMedianOfThree(int *A, int a, int b, int c) // 중간값 찾기
{
    if ((A[a] >= A[b] && A[a] <= A[c]) || (A[a] <= A[b] && A[a] >= A[c]))
    {
        return a;
    }
    else if ((A[b] >= A[a] && A[b] <= A[c]) || (A[b] <= A[a] && A[b] >= A[c]))
    {
        return b;
    }
    else
    {
        return c;
    }
}

int findPivot(int *A, int l, int r, char *mode) // 각 모드에 맞는 pivot값 찾기
{
    if (strcmp(mode, "deterministic1") == 0) // 결정적1 버전 수행 시에는 첨자 r 반환
    {
        return r;
    }
    else if (strcmp(mode, "randomized1") == 0) // 무작위1 버전 수행 시에는 첨자 l과 r사이의 무작위 위치를 반환
    {
        srand(time(NULL));

        int dif = r - l;    // 두 인덱스의 차이
        return l + (rand() % (dif + 1)); // 두 인덱스 사이의 랜덤한 인덱스 반환
    }
    // 결정적 3또는 무작위3 버전 수행시에는 부배열의 크기가 3미만이면 앞 위치를 반환
    // 그렇지 않으면 수행 버전에 따라 작업 내용이 달라짐,
    else if (strcmp(mode, "deterministic3") == 0) // 결정적3 버전 수행 시에는 배열 A의 첨자 l과 r사이 원소들 가운데 맨 앞, 중간 맨 뒤 원소의 중앙값을 반환
    {
        int a = l;        // 첫번째 인덱스
        int b = (l + r) / 2; // 중간 인덱스
        int c = r;      // 마지막 인덱스

        return findIndexOfMedianOfThree(A, a, b, c);    // 세개의 인덱스중에 value값이 중간값인 인덱스 찾기
    }
    else if (strcmp(mode, "randomized3") == 0) // 무작위3 버전 수행 시에는 배열 A의 첨자 l과 r사이 원소들 가운데 무작위 세 원소의 중앙값 위치 반환
    {
        srand(time(NULL));

        int dif = r - l;    // 두 인덱스의 차이
        int a = l + (rand() % (dif + 1)); // 두 인덱스 사이의 랜덤한 인덱스 반환
        int b = l + (rand() % (dif + 1)); // 두 인덱스 사이의 랜덤한 인덱스 반환
        int c = l + (rand() % (dif + 1)); // 두 인덱스 사이의 랜덤한 인덱스 반환

        return findIndexOfMedianOfThree(A, a, b, c); // 세개의 인덱스중에 value값이 중간값인 인덱스 찾기
    }
    return -1;
}

int inPlacePartition(int *L, int l, int r, int k) // 파티션을 나누는 함수
{

    int temp, i = l, j = r - 1, p = L[k]; // p는 피벗값, i는 왼쪽 인덱스, j는 오른쪽 인덱스

    temp = L[k]; // 피벗값과 맨 끝의 인덱스의 값을 바꿔줌
    L[k] = L[r];
    L[r] = temp;

    while (i <= j) // i가 j보다 작거나 같을 때까지 반복
    { 

        while (i <= j && L[i] < p) // i가 j보다 작거나 같고, L[i]가 피벗값보다 작을 때까지 반복
        {
            i++;
        }

        while (j >= i && L[j] >= p) // j가 i보다 크거나 같고, L[j]가 피벗값보다 크거나 같을 때까지 반복
        {
            j--;
        }

        if (i < j) // i가 j보다 작을 때
        {
            temp = L[i]; // L[i]와 L[j]의 값을 바꿔줌
            L[i] = L[j];
            L[j] = temp;
        }
    }

    temp = L[i]; // L[i]와 L[r]의 값을 바꿔줌
    L[i] = L[r];
    L[r] = temp;

    j = r - 1;  // j를 r-1로 초기화

    return i;   // i를 반환
}   

void rQuicksort(int *A, int l, int r, char *mode)
{

    if (r - l >= Limit)
    {

        int pivot = findPivot(A, l, r, mode); // 각 모드에 맞는 피벗을 찾음
        int a = inPlacePartition(A, l, r, pivot); 
        // 피벗을 기준으로 분할, a는 피벗의 위치 인덱스, l부터 a-1까지는 피벗보다 작은 값, a+1부터 r까지는 피벗보다 큰 값
        // 제자리 분할이기 때문에 분할된 배열의 값이 바뀜

        rQuicksort(A, l, a - 1, mode); //피벗보다 작은 값들을 재귀적으로 정렬
        rQuicksort(A, a + 1, r, mode);  //피벗보다 큰 값들을 재귀적으로 정렬
    }
}

void insertionSort(int *arr, int n) // insertionsort 
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

void quickSort(int *A, char *mode)
{

    rQuicksort(A, 0, n - 1, mode);  // 재귀적으로 sort 진행
    if (Limit > 1)
    {
        insertionSort(A, n); // Limit보다 작은 부분은 삽입정렬로 정렬
    }
}

void printCpuTime(clock_t start, clock_t end)
{
    printf("%lf\t", (double)(end - start) / CLOCKS_PER_SEC);    // CPU time 초 단위로 출력
}

void copyArray(int A[], int B[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}

int main()
{
    int *A = createArray(); // 배열 생성
    clock_t start, end;

    printf("Limit\t\t결정적1\t\t결정적3\t\t무작위1\t\t무작위3\n");

    for (int i = 0; i < 4; i++)
    {
        char *mode_str = 0;

        Limit = Limits[i];  // Limit을 1, 10, 100, 1000으로 설정
        printf("%d\t\t", Limits[i]);    // Limit 출력

        for (int j = 0; j < 4; j++) // 결정적1, 결정적3, 무작위1, 무작위3 순으로 반복
        {
            int *B = (int *)malloc(sizeof(int) * n);    // 배열 B 생성

            copyArray(A, B, n); // 배열 A를 배열 B에 복사
            mode_str = mode[j]; // mode_str에 결정적1, 결정적3, 무작위1, 무작위3 중 하나를 저장

            start = clock();    // 시작 시간 측정
            quickSort(B, mode_str); // quickSort 실행
            end = clock();  // 종료 시간 측정

            printCpuTime(start, end);   // 실행 시간 출력
            free(B);        // 배열 B 메모리 해제
        }
        printf("\n");   // Limit이 바뀔 때마다 줄바꿈
    }
    free(A);
    return 0;
}