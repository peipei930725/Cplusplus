#include<stdio.h>
#include<stdlib.h>

int main() {
	int num1 = 0, num2 = 0;
		while (scanf_s("%d%d", &num1, &num2) !=EOF) {
		int len = 0, count = 0, countlen = 0;
		if (num1 == 0 && num2 == 0) {
			return 0;
		}
		if (num1 >= 0 || num2 >= 0) {
			len = num1 + num2;
			while (len!=0) {
				len = len / 10;
				countlen++;
			}
			int countarr[10] = { 0 };
			for (int i = 1; i <= countlen-1; ++i) {
				int test = (num1 % 10 + num2 % 10) + countarr[i];
				if (((num1 % 10  + num2 % 10 ) + countarr[i]) >= 10) {
					countarr[i + 1] = 1;
					count = count + 1;
				}
				num1 = num1 / 10;
				num2 = num2 / 10;
			}
			switch (count) {
			case 0:
				printf("NO carry operation.\n");
				break;
			case 1:
				printf("1 carry operation.\n");
				break;
			default:
				printf("%d carry operations.\n",count);
				break;
			}
		}
	}
	system("pause");
	return 0;
}
