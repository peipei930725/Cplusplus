#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	long long int grade1, grade2, grade3,avg;
	printf("��J������1\n");
	scanf("%lld", &grade1);
	printf("��J������2\n");
	scanf("%lld", &grade2);
	printf("��J������\n");
	scanf("%lld", &grade3);
	printf("��J�������Z\n");
	scanf("%lld", &avg);

	for (int i = 1; i <= 101; ++i) {
		long long int sum = 0, avg2 = 0;
		sum = ((grade1 * i) % 101) * 0.22 + ((grade2 * i) % 101) * 0.23 + ((grade3 * i) % 101) * 0.25 + 24.7+1;
		avg2 = (avg * i) % 101;
		if (avg2 - 1 <= sum && sum <= avg2 + 1) {
			printf("\n�K�y��:%lld", i);
			printf("�A���u�ꦨ�Z��%lld\n", sum);
			printf("�Ĥ@��������%lld\n", (grade1 * i) % 101);
			printf("�ĤG��������%lld\n", (grade2 * i) % 101);
			printf("�Ĥ@��������%lld\n", (grade3 * i) % 101);
		}
	}
	system("pause");
	return 0;
}