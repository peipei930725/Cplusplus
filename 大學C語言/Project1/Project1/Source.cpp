#include<stdio.h>
#include<stdlib.h>


int main() {
	int sum = 0, a = 0;
	do {
		printf("½Ð¿é¤J¼Æ¦r");
		sum += a;
	} while (scanf_s("%d", &a));

	printf("%d", sum);

	system("pasue");
}