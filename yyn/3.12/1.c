#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

int main() {
    double a, b, c, delta, m, n;
    printf("请输入一元二次方程的系数a, b, c:");
    scanf ("%lf %lf %lf", &a, &b, &c);
    delta = b * b - 4 * a * c;

    if (a == 0) {
        printf("不是二次方程\n");
    }
    else {
        if (delta == 0) {
            double root = -b / (2 * a);
            printf("方程有两个相等的实根: x = %7.2lf\n", root);
        }
        else if (delta > 0) {
            double root1 = (-b + sqrt(delta)) / (2 * a);
            double root2 = (-b - sqrt(delta)) / (2 * a);
            printf("方程有两个不等的实根: x1 = %7.2lf, x2 = %7.2lf\n", root1, root2);
        }
        else {
            m = -b / (2 * a);
            n = sqrt(-delta) / (2 * a);
            printf("方程有两个共轭复根: x1 = %7.2lf + %7.2lfi, x2 = %7.2lf - %7.2lfi\n", m, n, m, n);
        }
    }

    return 0;
}