#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265359
#pragma warning(disable:4996)

int main() {
	int testcase;
	scanf("%d", &testcase);
	int Fibonacci[40] = { 0, 1 };
	int i;

	for (i = 2; i < 40; i++) {
		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
	}
	while (testcase--) {
		int num;

		scanf("%d", &num);
		printf("%d = ", num);
		
	}
}