#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main(){
    int arr[100]={0},count=0,num=0;
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        scanf("%d",&arr[i]);
        if(arr[i]%2==1)
            count++;
    }
    if(count>=(num/2+num%2))
        printf("%d",num-count);
    else
        printf("%d",count);
    return 0;
}