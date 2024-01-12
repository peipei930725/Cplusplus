#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int main() {
	int hour1, min1 = 0;
	int hour2, min2 = 0;
	scanf("%d:%d", &hour1,&min1);
	scanf("%d:%d", &hour2, &min2);
	int avg = ((hour1+hour2)*60+min1+min2) / 2;
	int avgmin = (avg - (avg / 60) * 60);

	if ((avg / 60) < 10 && avgmin < 10)
		printf("0%d:0%d", avg / 60, avgmin);
	else if ((avg / 60) < 10)
		printf("0%d:%d", avg / 60, avgmin);
	else if (avgmin < 10)
		printf("%d:0%d", avg / 60, avgmin);
	else
		printf("%d:%d", avg / 60, avgmin);

	return 0;
}