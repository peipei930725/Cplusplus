#include<stdio.h>
#include<stdlib.h>

int main() {
	__int64 people = 0;
	scanf_s("%d", &people);
	if (people % 2 == 0)
		printf("%d\n", people +1);
	else
		printf("%d\n", people/2+1);
	system("pause");
}