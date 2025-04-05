#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
long long MAX=2e5; 
int main() {
       int n,m,k=0;
       scanf("%d",&n);
    char strSrc[MAX];
    scanf("%s",strSrc);
    scanf("%d",&m);
    char strDst[MAX];
    for(int i=m-1;i<n;i++){
        if(strSrc[i]=='\0'||strSrc[i]=='\n')  break;
        strDst[k]=strSrc[i];
        k++;
    }
    strDst[k]='\0';
    printf("%d \n",k);
    for(int i=0;i<k;i++){
        if(strDst[i]!='\0')
        printf("%c",strDst[i]);
    }
}