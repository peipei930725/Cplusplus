#include<stdio.h>
#include<stdlib.h>

void fun(int* num1, int* num2) {
	printf("%p %p\n",num2,num1);
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main() {
	int x1, x2;
	scanf_s("%d%d",&x1, &x2);
	fun(&x1, &x2);

	printf("%d %d\n", x1, x2);

	system("pause");
	return 0;
}