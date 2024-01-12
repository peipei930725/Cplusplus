#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main(){
    int *ptr=NULL;
    ptr=(int *)malloc(sizeof(int)*3);
    for(int i=0;i<3;++i){
        ptr[i]=0;
        scanf("%d",&ptr[i]);
    }

    for(int i=0;i<3;++i){
        printf("%d",ptr[i]);
    }


    free(ptr);

    return 0;
}