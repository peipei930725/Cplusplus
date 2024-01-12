#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct test1 {
	char ch1;
	long long int num;
	int num1;
	char ch2;
	int num2;
};

int main() {
	printf("%d", sizeof(test1));

	system("pause");
	return 0;
}