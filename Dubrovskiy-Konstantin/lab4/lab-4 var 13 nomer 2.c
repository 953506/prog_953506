#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define N 12  /* ���������� �������� � ������ */

//------------------- ���������� ���������� ��.953506 --------------------
//-------------------          �.�.�4 (���.13)       ---------------------
//  4.2(13):  ����� � ����� �������� �����, ������� �������� � ������������
//			 ������� ���������. ������������� ��� ����� � ���������� �������
//			 ��������� � �������� ����������������� ����� ������� � ����.
//------------------------------------------------------------------------

void IntToSrt(int n, char *str);
int MyFoo(char *str);

int _tmain()
{
	char buffer[N];
	FILE *fin, *fout;   // ��������� �� ����

	fin = fopen("C:\\work\\prog\\laba4\\file_in.txt", "r"); // ������� ���� file_in.txt
	fout = fopen("C:\\work\\prog\\laba4\\file_out.txt", "w"); // ������� ���� file_out.txt
	if (!fin || !fout)  // ���� ���� �� ������ � �����
	{
		printf("file is not open! :( \n");
        getch();
		exit(1);
	}
	printf("num8 = num10\n------------------\n");
	// ��������� ������ �� ����� � buffer ���������
	while (fgets(buffer, N, fin) != NULL)
	{
		char num10[N] = "\0";
		int n = 0;

		n = MyFoo(buffer); //����������� ��������. ����� ���������� ���� � �������. ����� ���� int		
		// B���� �� �����:
		printf("num8: ");
		puts(buffer);  
		printf("num10: %d\n------------------\n", n);

		IntToSrt(n, num10); //����� � ������

		fputs(num10, fout); //����� � ����
	}

	fclose(fin); /* ������� ����� */
	fclose(fout);

    system ("pause");
	return 0;
}

int MyFoo(char *str)
{
	int len = 0, n = 0; 
	bool minus = false;
	
	while(str[len] != '\n')
	{
		if (str[len] == '-') minus = true; //��� ������������� �����
		len++; //���������� ����� ������
	}

	if(!minus) //��� ������������� �����
	{
		int i = 0;
		
		while(i < len)
		{
			n += (str[i] - '0') * pow(8, len - i - 1);  //�� �-�� �������� �� 8-��. � 10-��. ����. ��.
			i++;	
		}
	}
	else //��� ������������� �����
	{
		int i = 1;
		
		while(i < len)
		{
			n += (str[i] - '0') * pow(8, len - i - 1);  //�� �-�� �������� �� 8-��. � 10-��. ����. ��.
			i++;	
		}
		n *= -1; //�������� ���� ������	
	}
	return n;
}

void IntToSrt(int n, char *str)
{
	char strrev[N]; //�������� ����� �����-�������
	int len = 0; //����� ����� n � ��������               
	bool minus = false;        

	if(n < 0) //���� n �������������
	{
		minus = true; //���������� �����
		n *= -1;  //���������� n ������������� ��������
	}
	
	while(n >= 10)
	{
		char ch = '0' + n % 10;
		strrev[len] = ch;
		n /= 10;
		len++;
	}  	
	strrev[len] = '0' + n;

	if(!minus) //��� �������������
	{
		int i = 0, j = len;

		while(j >= 0)
		{
			str[i] = strrev[j];  //����������� ������
			i++;
			j--;	
		}
		str[len + 1] = '\n';
	}
	else //��� �������������
	{
		int i = 1, j = len;
		
		str[0] = '-';
		while(j >= 0)
		{
			str[i] = strrev[j];  //����������� ������ 
			i++;
			j--;	
		}
		str[len + 2] = '\n';
	}	
}
