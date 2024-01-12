#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int sum,dif;
        scanf("%d %d",&sum,&dif);
        int a,b;
        a=sum+dif;
        b=sum-dif;
        if(a<0||b<0||a%2!=0||b%2!=0)
            printf("impossible\n");
        else {
            printf("%d %d\n",a/2,b/2);
        }
    }
    return 0;
}