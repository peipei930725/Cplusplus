#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct student {
    char name[20];
    int math;
    int english;
};

int main() {
    char str[200];
    char delim[] = " ";
    scanf("%s",str)

    char* ptr = strtok(str, delim);

    while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, delim);
    }

    system("pause");
    return 0;
} 