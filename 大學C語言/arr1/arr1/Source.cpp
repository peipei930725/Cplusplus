#include<stdio.h>
#include<stdlib.h>
#define arr_len 5

int i = 0;

void input(int a[]) {
	if (i < arr_len) {
		printf("第%d個數為%d ", i, a[i]);
		i += 1;
		input(a[i]);
	}
	return;	
}

int main() {
	int num1 = 0;
	int arr[arr_len] = { 0 };
	for (int i = 0; i < arr_len; ++i) {
		scanf_s("%d", &arr[i]);
	}
	scanf_s("%d", &num1);
	input(arr[]);

	return 0;
}