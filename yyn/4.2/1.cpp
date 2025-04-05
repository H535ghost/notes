#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int joseph(int numbers[],int n,int m){
     int k=1;
     int p=-1,q=1; 
     int num[100000];
     for(int i=0;i<100000;i++){
        num[i]=-1;
      }
     while(k){
        for(int i=0;i<m;i++){
            p++;
            p=p%n;
            while(num[p]!=-1) {p++;p=p%n;}          
        }
        num[p]=q;
        numbers[q-1]=p+1;
        if(q==n) return p+1;
        q++;
     }
     return 0;
}
int main() {
      int n,m;
      int num[100000];
    scanf("%d %d",&n,&m);
    printf("%d \n",joseph(num,n,m));
    for(int i=0;i<n-1;i++){
        printf("%d \n",num[i]);
    }
}