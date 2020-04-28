#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void create_outF(int num, int sNum, char sType[5],int max, int brack,int deci, int output)//文件中输出
{
	int questionNum = num;//题目数量
	int symbolNum = sNum;//运算符种类数
	char symbolType[5];
	strcpy(symbolType, sType);//运算符
	int  maxNum = max;//最大值
	int brackets = brack;//是否有括号
	int decimal = deci;//是否有小数
	int outputMode = output;//输出方式
	float number[5];//数字
	char symbol[4];//运算符
	int bracketsPosition;//括号位置

    
  
    printf(" 生成文件成功\n");
  
    srand((int)time(0));//随机数不同
    FILE* fp;
    fp = fopen("四则运算.txt", "w");//文件写操作
    for (int t = 0; t < questionNum; t++)//随机数字
    {
        for (int i = 0; i < 5; i++)
        {
            if (decimal == 0)//随机整数
            {
                number[i] = rand() % (maxNum + 1);
            }
            else//随机小数
            {
                number[i] = rand() % maxNum;
                number[i] = number[i] + rand() % 100 * 0.01;
            }
        }
        for (int i = 0; i < 4; i++)//随机符号
        {
            symbol[i] = symbolType[rand() % symbolNum];
        }
        for (int i = 0; i < 4; i++)
        {
            if ((symbol[i] == '/') && (number[i + 1] == 0))//除数不为0
            {
                number[i + 1]++;
            }
        }
        
        if (outputMode == 2)//输出到文件
        {
            if (decimal == 1)//整数
            {
                if (brackets == 1)//无括号
                {
                    fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//有括号
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//一二数间括号
                    {
                        fprintf(fp, "（%.0f%c%.0f）%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//二三数间括号
                    {
                        fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//三四数间括号
                    {
                        fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//四五数间括号
                    {
                        fprintf(fp, "%.0f%c%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
            if (decimal == 2)//小数
            {
                if (brackets == 1)//无括号
                {
                    fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//有括号
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//一二数间括号
                    {
                        fprintf(fp, "（%.2f%c%.2f）%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//二三数间括号
                    {
                        fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//三四数间括号
                    {
                        fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 3)//四五数间括号
                    {
                        fprintf(fp, "%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
        }

    }
   
        if (decimal == 2)//小数
        {
            if (brackets == 1)//无括号
            {
                printf("                 ");
                printf("%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (brackets == 2)//有括号
            {
                printf("                 ");
                bracketsPosition = rand() % 4;
                if (bracketsPosition == 0)//一二数间括号
                {
                    printf("                 ");
                    printf("（%.2f%c%.2f）%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 1)//二三数间括号
                {
                    printf("                 ");
                    printf("%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 2)//三四数间括号
                {
                    printf("                 ");
                    printf("%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 3)//四五数间括号
                {
                    printf("                 ");
                    printf("%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
            }
        }

        fclose(fp);//关闭文件
 }
          
        
       