#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <string.h>
#include <stdlib.h>

int main()
{
    char num1[10];
    char sign;
    int num2;
    char input[50];
    int result, yushu = 0;
    char compare1[] = "sin";
    char compare2[] = "cos";
    char compare3[] = "tan";
    char exit[] = "exit";
    int mode = -1;//mode=1是三角函数模式，mode=2是加减乘除模式
    int sanjiao = -1;
    int verify = 0;
    int NUM1 = 0, SIGN;
    while (1) {
        printf("请输入算式：");
        scanf("%9s %c %d", num1, &sign, &num2);
        if (strcmp(num1, exit) == 0) {
            break;
        }
        if (strcmp(num1, compare1) == 0) {
            //printf("输入的是sin");
            mode = 1;
            verify++;
            sanjiao = 1;
        }
        if (strcmp(num1, compare2) == 0) {
            //printf("输入的是cos");
            mode = 1;
            verify++;
            sanjiao = 2;
        }
        if (strcmp(num1, compare3) == 0) {
            //printf("输入的是tan");
            mode = 1;
            verify++;
            sanjiao = 3;
        }
        if (sign == '+' || sign == '-' || sign == '*' || sign == '/') {
            //printf("输入的是+");
            mode = 2;
            verify++;
        }
        if (verify == 2) {
            printf("请输入正确的算式！");
        }
        else {
            if (mode == 1) {
                printf("三角函数模式\n");
                SIGN = (int)(sign);
            }
            else if (mode == 2) {
                printf("加减乘除模式\n");
                NUM1 = atoi(num1);
                if (sign == '+') {
                    result = (int)(NUM1)+(int)(num2);
                }
                if (sign == '-') {
                    result = (int)(NUM1)-(int)(num2);
                }
                if (sign == '*') {
                    result = (int)(NUM1) * (int)(num2);
                }
                if (sign == '/') {
                    result = (int)(NUM1) / (int)(num2);
                    yushu = (int)(NUM1) % (int)(num2);
                }
            }
            if (mode == -1) {
                printf("算式格式不正确");
            }
            printf("输入的算式是：");
            if (mode == 1) {
                if (sanjiao == 1) {
                    printf("sin");
                }
                else if (sanjiao == 2) {
                    printf("cos");
                }
                else {
                    printf("tan");
                }
                printf("%c\n", sign);
                printf("计算结果：");
                printf("三角函数输出\n");
            }
            if (mode == 2) {
                if (yushu == 0) {
                    printf("%d %c %d\n", NUM1, sign, num2);
                    printf("计算结果：");
                    printf("%d", result);
                }
                else {
                    printf("%d余%d", result, yushu);
                }
            }
        }
        return 0;

    }
}