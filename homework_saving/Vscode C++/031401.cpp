#include<stdio.h>
#pragma warning(disable:4996)

int main(){

    int v, t;

    while(scanf("%d %d", &v, &t) != EOF){
        printf("%d\n", 2 * v * t);
    }

    return 0;
}