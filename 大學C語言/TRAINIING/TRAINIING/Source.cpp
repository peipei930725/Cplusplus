#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#pragma warning(disable:4996)

int main() {
	char str[99] = { 0 };
	scanf("%[^\n]", &str);
	printf("¤p¼g:");
	for (int i = 0; i < 99; ++i) {
		printf("%c", tolower(str[i]));
	}
	printf("\n¤j¼g:");
	for (int i = 0; i < 99; ++i) {
		printf("%c", toupper(str[i]));
	}
	system("pause");
	return 0;
}