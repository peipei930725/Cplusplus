#include<stdio.h>
#include<stdlib.h>

int oddoreven(int num) {
	if (num % 2 == 0 || num == 0)
		return 1;
	else
		return 0;
}
int main() {
	int number = 0;
	printf("�п�Jx:");
	scanf_s("%d", &number);
	if (oddoreven(number))
		printf("%d�O����\n", number);
	else
		printf("%d�O�_��\n", number);

	system("pause");
	return 0;
}
