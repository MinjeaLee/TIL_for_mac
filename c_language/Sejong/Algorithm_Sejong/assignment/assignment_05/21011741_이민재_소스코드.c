#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 30

int airtelDC(int n, int s, int d);
int rAirtelDC(int n, int s, int d);
int airtelDP(int n, int s, int d);
int min(int a, int b);

int H[30]; 	// 숙박 요금 H
int A[30];	// 항공 요금 A
int m[30];	// 최소 비용 m

int main() {
	int n, min_1, min_2;
	double cpu_time; 				// CPU 시간

	clock_t ticksPerSec = CLOCKS_PER_SEC;	// 1초에 몇 틱인지
	clock_t start, end, diff;			

	A[0] = 0; 
	A[1] = 1;

	for (int i = 2; i < MAX; i++)			// 항공 요금 A 계산
		A[i] = A[i - 1] + A[i - 1] % 5 + 3; // 이후 A배열 초기화
	

	H[0] = 0; 					// 0 지점 숙박 요금 0
	H[1] = 5; 					// 1 지점 숙박 요금 5

	for (int i = 2; i < MAX; i++) 
		H[i] = (H[i - 1] + i)% 9 + 1; 		// 이후 H배열 초기화
	
	printf("n\ts\td\tminocst\tversion\tcputime\n");

	n = 6;					// n = 6 일때

	int s[4] = {0, 2, 2, 1}; 	// 경우의 수에 따른 출발점 s
	int d[4] = {4, 5, 4, 28}; 	// 경우의 수에 따른 도착점 d

	for (int i = 0; i < 3; i++) { 			// 3가지 경우의 수
		start = clock();					// 시작 시간
		min_1 = airtelDC(n, s[i], d[i]); 	// 최소 비용 계산, 분할 통치
		end = clock();						// 종료 시간
		diff = end - start;					// 시간 차이
		cpu_time = ((double)diff / (double)ticksPerSec);	// 차이를 CPU 시간으로 변환

		printf("%d\t%d\t%d\t%2d\tDC\t%.8f\n", n, s[i], d[i], min_1, cpu_time);

		start = clock();				
		min_2 = airtelDP(n, s[i], d[i]); 	// 최소 비용 계산, 동적 계획법
		end = clock();
		diff = end - start;
		cpu_time = ((double)diff / (double)ticksPerSec);

		printf("%d\t%d\t%d\t%2d\tDP\t%.8f\n", n, s[i], d[i], min_2, cpu_time);	
	}

	n = MAX; 	// n = 30 일때, MAX일때

	start = clock();
	min_1 = airtelDC(n, s[3], d[3]); 			// 최소 비용 계산, 분할 통치
	end = clock();
	diff = end - start;
	cpu_time = ((double)diff / (double)ticksPerSec);

	printf("%d\t%d\t%d\t%d\tDC\t%.8f\n", n, s[3], d[3], min_1, cpu_time);
	
	start = clock();
	min_2 = airtelDP(n, s[3], d[3]); 			// 최소 비용 계산, 동적 계획법
	end = clock();
	diff = end - start;
	cpu_time = ((double)diff / (double)ticksPerSec);

	printf("%d\t%d\t%d\t%d\tDP\t%.8f\n", n, s[3], d[3], min_2, cpu_time);

	return 0;
}

int airtelDC(int n, int s, int d) {	// 최소 비용 계산, 분할 통치
	return rAirtelDC(n, s, d); 		// 재귀 함수 호출, 최소 비용 반환
}

int rAirtelDC(int n, int s, int d) {
	int min_cost = INT_MAX; 			// 최소 비용 저장 변수, 초기값 INT_MAX
	int cost = 0; 

	if (d == s) 							// 출발점과 도착점이 같으면 0 반환
		return 0; 
	for (int k = s; k < d; k++) {			// 출발점부터 도착점까지 반복
		if (k == s) 						// 출발점과 도착점이 같으면
			cost = rAirtelDC(n, s, k) + A[d - k]; 		// 재귀 호출, 최소 비용 계산, A[d - k] 더함
			
		else 								// 출발점과 도착점이 다르면
			cost = rAirtelDC(n, s, k) + H[k] + A[d - k]; // 재귀 호출, 최소 비용 계산, H[k]와 A[d - k] 더함

		min_cost = min(min_cost, cost); 		// 최소 비용 저장
	}

	return min_cost; 
}

int airtelDP(int n, int s, int d) {		// 최소 비용 계산, 동적 계획법
	int cost = 0; 							// 비용 저장 변수

	for (int i = 0; i <= s; i++) 			// m 배열 초기화
		m[i] = 0; 

	for (int j = s + 1; j <= d; j++) {		// 출발점부터 도착점까지 반복
		m[j] = INT_MAX; 						// m 배열 초기화, 최소 비용 저장 변수, 초기값 INT_MAX
		for (int k = s; k < j; k++) {		// 출발점부터 도착점까지 반복
			if (k == s) 						// 출발점과 도착점이 같으면
				cost = m[k] + A[j - k];  			// m[k]와 A[j - k] 더함
			else 		
				cost = m[k] + H[k] + A[j - k];	// m[k]와 H[k]와 A[j - k] 더함 

			m[j] = min(m[j], cost);		// 최소 비용 저장
		}
	}
	return m[d]; 
}

int min(int a, int b) {
	if (a < b) 
		return a; 
	else 
		return b; 
}