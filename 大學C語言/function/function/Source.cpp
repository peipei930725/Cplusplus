#include<stdio.h>
#include<stdlib.h>

/*nt
}*/

int division(int a,int b) {
	if (a % b == 0) 
		return b;
	else
		return division(b, a % b);
}

int main(){
	int num1 = 0, num2 = 0;
	printf("�п�Ja,b�⥿���:");
	scanf_s("%d %d", &num1, &num2);

	printf("�̤j���]�Ƭ�%d\n", division(num1, num2));

	system("pause");
	return 0;
}
