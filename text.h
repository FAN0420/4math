#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void create_outF(int num, int sNum, char sType[5],int max, int brack,int deci, int output)//�ļ������
{
	int questionNum = num;//��Ŀ����
	int symbolNum = sNum;//�����������
	char symbolType[5];
	strcpy(symbolType, sType);//�����
	int  maxNum = max;//���ֵ
	int brackets = brack;//�Ƿ�������
	int decimal = deci;//�Ƿ���С��
	int outputMode = output;//�����ʽ
	float number[5];//����
	char symbol[4];//�����
	int bracketsPosition;//����λ��

    
  
    printf(" �����ļ��ɹ�\n");
  
    srand((int)time(0));//�������ͬ
    FILE* fp;
    fp = fopen("��������.txt", "w");//�ļ�д����
    for (int t = 0; t < questionNum; t++)//�������
    {
        for (int i = 0; i < 5; i++)
        {
            if (decimal == 0)//�������
            {
                number[i] = rand() % (maxNum + 1);
            }
            else//���С��
            {
                number[i] = rand() % maxNum;
                number[i] = number[i] + rand() % 100 * 0.01;
            }
        }
        for (int i = 0; i < 4; i++)//�������
        {
            symbol[i] = symbolType[rand() % symbolNum];
        }
        for (int i = 0; i < 4; i++)
        {
            if ((symbol[i] == '/') && (number[i + 1] == 0))//������Ϊ0
            {
                number[i + 1]++;
            }
        }
        
        if (outputMode == 2)//������ļ�
        {
            if (decimal == 1)//����
            {
                if (brackets == 1)//������
                {
                    fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//������
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//һ����������
                    {
                        fprintf(fp, "��%.0f%c%.0f��%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//������������
                    {
                        fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.0f%c%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
            if (decimal == 2)//С��
            {
                if (brackets == 1)//������
                {
                    fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (brackets == 2)//������
                {
                    bracketsPosition = rand() % 4;
                    if (bracketsPosition == 0)//һ����������
                    {
                        fprintf(fp, "��%.2f%c%.2f��%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 1)//������������
                    {
                        fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 2)//������������
                    {
                        fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                    if (bracketsPosition == 3)//������������
                    {
                        fprintf(fp, "%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                    }
                }
            }
        }

    }
   
        if (decimal == 2)//С��
        {
            if (brackets == 1)//������
            {
                printf("                 ");
                printf("%.2f%c%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
            }
            if (brackets == 2)//������
            {
                printf("                 ");
                bracketsPosition = rand() % 4;
                if (bracketsPosition == 0)//һ����������
                {
                    printf("                 ");
                    printf("��%.2f%c%.2f��%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 1)//������������
                {
                    printf("                 ");
                    printf("%.2f%c(%.2f%c%.2f)%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 2)//������������
                {
                    printf("                 ");
                    printf("%.2f%c%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
                if (bracketsPosition == 3)//������������
                {
                    printf("                 ");
                    printf("%.2f%c%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3], symbol[3], number[4]);
                }
            }
        }

        fclose(fp);//�ر��ļ�
 }
          
        
       