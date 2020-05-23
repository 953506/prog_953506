#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <malloc.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//---------- ���������� ���������� __ ��.953506 __ �.�. �3 __ ���. 3.2(22) -------------------

//      ������� 3.2(22):
//	 	����������� ����������� ����� ������� �� ������ �� ������ �� ������ ���� �����
// 		��������������� ���������. �������� ������: si � ���������� �� ������ ������, �;
//	 	hi � ������� ����, �; vi � �������� �������, �/�, i = 1, 2,..., n.
//		����� ������ ���� � �������, �.�. ������� ���������� ���� ��������� ����� ������� ���� � �������?
//---------------------------------------------------------------------------------------------

void DataInput (float *s, float *v, float *h, int n)
{
	printf("Enter your data in the table:\n");  //"������� ���� ������ � ��������:"
	printf("n: \t S(m): \t V(m/s) \t H(m)\n");
	for(int i = 0; i < n; i++)
	{
		int mistake = 0;  //������� ���������� ������ �����

		//���������� i-��� ����� �������
		printf("%d. \t ", i + 1);
		scanf(" %f", &s[i]);
		printf(" \t ");
		scanf(" %f", &v[i]);
		printf(" \t ");
		scanf(" %f", &h[i]);
		printf("\n");
		//�������� �� ������������ ����:
		if( (s[i] <= 0) || (s[i] > 40000) ) mistake++;  //���� ������ ����� < 0 ��� > 40 �� -- ������
		if( (v[i] <= 0) || (v[i] > 2) ) mistake++; //���� �������� ���. ����� < 0 ��� > 7,2 ��/� (2 �/�)
		if( (h[i] <= 0) || (h[i] > 2.5) ) mistake++; //���� ������� ����� < 0 ��� > 2.5 �
		if(mistake != 0)
		{
			printf("A mistake was found in the line. Enter the line again.\n");
			i--; //��� ����������� �� ��� �� ����� �� ��������� ��������
		}
	}
}

float Consumption (float s, float v, float h)
{
	return s * h * v;	//������ ���� � �������
}

void DataOutput (float *s, float *v, float *h, int n)
{
	printf("n: \t  S(m): \t V(m/s):\t H(m):\t Water consumption: \n");
	for(int i = 0; i < n; i++)
	{
		float consumption = Consumption(s[i], v[i], h[i]);

		printf("%d. \t %.2f \t %.2f \t\t  %.2f \t\t  %.2f \n", i + 1, s[i], v[i], h[i], consumption);
	}
	printf("\n");
}

int _tmain()
{
	int n = 0;
	float *s, *v, *h;   //���������� ������� ��� � �������

	printf("How many measurements were taken?\n"); // "������� ��������� ���������?"
	scanf(" %d", &n);
	s = (float*) malloc(n * sizeof(float));  //��������� ������ ��� �������
	v = (float*) malloc(n * sizeof(float));
	h = (float*) malloc(n * sizeof(float));
	//������ � �������������:
	while(1)  //��������. ���� (�1)
	{
		char answer;

		DataInput(s, v, h, n); //���� ������
		while(2) //��� ���� ���� (�2)
		{
			system("cls");
			DataOutput(s, v, h, n); //����� ������
			printf("Is everything right in the table?\n");  //������ � �������������
			printf("Y - yes, it's ok \nN - no, I want to change something\n");
			scanf(" %c", &answer);
			//��� ���������� ����� ����� 'y' ���� 'n':
			if( (answer == 'y') || (answer == 'n') ) break; //����� �� ����� 2 (else ���� ���������)
		}
		if(answer == 'y') break; //����� �� ����� 1 (else ����� �� ����)
		else system("cls");
	}
	//������� ������:
	free(s);
	free(v);
	free(h);
    system("pause");
	return 0;
}
