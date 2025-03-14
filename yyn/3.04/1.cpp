#include <bits/stdc++.h>
#define pi 3.14
int main(){
    float r,h;
    printf("请输入半径");
    printf("请输入高");
    scanf("%f",&r);
    scanf("%f",&h);
    printf("圆周长是%.2f\n",2*pi*r);
    printf("圆面积是%.2f\n",pi*r*r);
    printf("圆球表面积是%.2f\n",pi*r*r*4);
    printf("圆球体积是%.2f\n",pi*r*r*r*2/3);
    printf("圆柱体积是%.2f\n",pi*r*r*h);
    
    }