#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

int main() {
	char str[1000] = { 0 };
	int arr[500] = {0};
	scanf("%s", &str);
	char delim[] = " ";

	char* ptr = strtok(str, delim);

	while (ptr != NULL) {
		for (int i = 0; i < strlen(ptr); ++i) {
			arr[int(ptr[i])]++;
		}
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}
	for (int i = 0; i <= 25; ++i) {
		printf("%c的出現次數為%d\n", i+65, arr[65 + i] + arr[97 + i]);
	}

	system("pause");
	return 0;
}