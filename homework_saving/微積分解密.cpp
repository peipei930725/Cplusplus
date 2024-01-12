#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	long long int grade1, grade2, grade3,avg;
	printf("輸入期中考1\n");
	scanf("%lld", &grade1);
	printf("輸入期中考2\n");
	scanf("%lld", &grade2);
	printf("輸入期末考\n");
	scanf("%lld", &grade3);
	printf("輸入平均成績\n");
	scanf("%lld", &avg);

	for (int i = 1; i <= 101; ++i) {
		long long int sum = 0, avg2 = 0;
		sum = ((grade1 * i) % 101) * 0.22 + ((grade2 * i) % 101) * 0.23 + ((grade3 * i) % 101) * 0.25 + 24.7+1;
		avg2 = (avg * i) % 101;
		if (avg2 - 1 <= sum && sum <= avg2 + 1) {
			printf("\n密語為:%lld", i);
			printf("你的真實成績為%lld\n", sum);
			printf("第一次期中考%lld\n", (grade1 * i) % 101);
			printf("第二次期中考%lld\n", (grade2 * i) % 101);
			printf("第一次期末考%lld\n", (grade3 * i) % 101);
		}
	}
	system("pause");
	return 0;
}