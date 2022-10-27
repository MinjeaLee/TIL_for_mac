#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// findPivot과 inPlacePartition 함수를 이용하여 부배열의 크기가 Limit보다 클 때까지는 퀵정렬을 수행하고
// 부배열의 크기가 Limit보다 작아지면 삽입정렬로 전환하여 정렬을 마무리하는 quicksort알고리즘 작성

// 결정적1 버전 수행 시에는 첨자 r 반환
// 무작위1 버전 수행 시에는 첨자 l과 r사이의 무작위 위치를 반환
// 결정적 3또는 무작위3 버전 수행시에는 부배열의 크기가 3미만이면 앞 위치를 반환,
// 그렇지 않으면 수행 버전에 따라 작업 내용이 달라짐,
// 먼저, 결정적3 버전 수행 시에는 배열 A의 첨자 l과 r사이 원소들 가운데 맨 앞, 중간 맨 뒤 원소의 중앙값을 반환
// 무작위3 버전 수행 시에는 배열 A의 첨자 l과 r사이 원소들 가운데 무작위 세 원소의 중앙값 위치 반환

// 주함수에서 1~100000 사이의 중복 가능한 n = 100000개의 정수 키로 이루어 진 배열 A의 복사본에 대해 Limit = 1, 100, 500, 1000으로 변경하면서
// 앞서의 네 가지 퀵 정렬 버전을 차례로 수행하고 이들의 시간 성능을 비교하라

// 초기 입력 배열 A는 난수 발생 함수를 사용하여 무작위하게 생성하고 정렬할 때마다 A의 복사본을 만들어 사용함으로써
// 동일한 입력에 대한 성능 비교가 되게 하라
// 입력 배열의 원본을 생성하거나 복사본을 만드는 데 걸리는 시간은 실행 시간에서 제외하라

// 출력
// Limit\t결정적1\t결정적3\t무작위1\t무작위3
// 1\tx.xxxx\tx.xxxx\tx.xxxx\tx.xxxx
// 100\tx.xxxx\tx.xxxx\tx.xxxx\tx.xxxx
// 500\tx.xxxx\tx.xxxx\tx.xxxx\tx.xxxx
// 1000\tx.xxxx\tx.xxxx\tx.xxxx\tx.xxxx


int n = 100000;
int Limits[4] = {1, 100, 500, 1000};

// char **mode = {"deterministic1", "deterministic3", "randomized1", "randomized3"};

int initialize(){
    // rand seed
    srand((unsigned int)time(NULL));
    return 0;
}

int findPivot(int A[], int l, int r, int mode)
{
    int i, j, k, temp;
    int pivot;
    int mid = (l + r) / 2;

    switch (mode)
    {
    case 0: // 결정적1
        pivot = r;
        break;
    case 1: // 결정적3
        if (r - l < 3)
        {
            pivot = l;
        }
        else
        {
            if (A[l] > A[mid])
            {
                if (A[mid] > A[r])
                {
                    pivot = mid;
                }
                else if (A[l] > A[r])
                {
                    pivot = r;
                }
                else
                {
                    pivot = l;
                }
            }
            else
            {
                if (A[l] > A[r])
                {
                    pivot = l;
                }
                else if (A[mid] > A[r])
                {
                    pivot = r;
                }
                else
                {
                    pivot = mid;
                }
            }
        }
        break;
    case 2: // 무작위1
        pivot = rand() % (r - l + 1) + l;
        break;
    case 3: // 무작위3
        if (r - l < 3)
        {
            pivot = l;
        }
        else
        {
            i = rand() % (r - l + 1) + l;
            j = rand() % (r - l + 1) + l;
            k = rand() % (r - l + 1) + l;

            if (A[i] > A[j])
            {
                if (A[j] > A[k])
                {
                    pivot = j;
                }
                else if (A[i] > A[k])
                {
                    pivot = k;
                }
                else
                {
                    pivot = i;
                }
            }
            else
            {
                if (A[i] > A[k])
                {
                    pivot = i;
                }
                else if (A[j] > A[k])
                {
                    pivot = k;
                }
                else
                {
                    pivot = j;
                }
            }
        }
        break;
    }

    return pivot;
}

int inPlacePartition(int A[], int l, int r, int mode)
{
    int pivot = findPivot(A, l, r, mode);
    int pivotValue = A[pivot];
    int i = l - 1;
    int j = r + 1;
    int temp;

    while (1)
    {
        do
        {
            i++;
        } while (A[i] < pivotValue);

        do
        {
            j--;
        } while (A[j] > pivotValue);

        if (i >= j)
        {
            return j;
        }

        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void rQuickSort(int A[], int l, int r, int mode)
{
    int q;

    if (l < r)
    {
        q = inPlacePartition(A, l, r, mode);
        rQuickSort(A, l, q, mode);
        rQuickSort(A, q + 1, r, mode);
    }
}

void quickSort(int A[], int n, int mode)
{
    rQuickSort(A, 0, n - 1, mode);
}

void createArray(int A[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        A[i] = rand() % n + 1;
    }
}

void copyArray(int A[], int B[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}

void printCpuTime(clock_t start, clock_t end)
{
    printf("\t%lf", (double)(end - start) / CLOCKS_PER_SEC);
}


int main(){
    int i, j;
    int A[n];
    // int B[n];

    initialize();

    printf("Limit\t결정적1\t결정적3\t무작위1\t무작위3\n");

    int B[n];
    createArray(A, n);
    for (i = 0; i < 4; i++)
    {
        printf("%d", Limits[i]);

        for (j = 0; j < 4; j++)
        {
            copyArray(A, B, n);

            clock_t start = clock();
            quickSort(B, Limits[i], j);
            clock_t end = clock();

            printCpuTime(start, end);
        }

        printf("\n");
    }

    return 0;
}