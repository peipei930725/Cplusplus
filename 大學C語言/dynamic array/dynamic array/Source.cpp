#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	long long int* ptr = NULL;
	int* ptr1 = NULL;

	ptr = new long long int(10);
	ptr1 = (int*)malloc(sizeof(int) * 3);

	printf("%d\n", *ptr);
	printf("%d\n", sizeof(*ptr1));

	free(ptr);
}