#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main(){
    int t=0;
    scanf("%d",&t);
    while(t--){
        int n=0,k=0,d=0;//n=數列長度,k=頻道大小,d=連續天數
        scanf("%d %d %d",&n,&k,&d);
        int arr[100]={0};
        for(int i=0;i<n;++i){//輸入第幾天播甚麼
            scanf("%d",&arr[i]);
        }
        int min=100;
        for(int i=0;i<n-d;++i){//逐一檢查
            int days[100]={0};
            int count=d,a=0;
            for(int j=i;j<d;++j){//分到另一個陣列
                days[a]=arr[j];
                a++;
            }
            for(int j=0;j<d;++j){
                for(int l=j+1;l<d;++l){
                    if (days[j]==days[l])
                        days[l]=0;
                }
            }
            for(int j=0;j<d;++j){
                if(days[j]!=0)
                    count--;
            }
            if(count<min)
                min=count;
        }
        printf("%d\n",min);
    }
    return 0;
}