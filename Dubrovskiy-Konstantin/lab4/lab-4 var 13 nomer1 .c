#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

//------------------- ���������� ���������� ��.953506 --------------------
//-------------------          �.�.�4 (���.13)       ---------------------
//  4.1(13):  ������ � ���������� ����������� ����� n <= 1000 � ������, ����������� �����.
//			  ������� �� ����� ��������� ����� �������� ������� � �������� ������.
//------------------------------------------------------------------------

void Proverka (int *n, char *ch); //�������� ������������ ����� ����� � ������
void Tysiachi(int *n, char *ch);  // �������� 1000
void Edinici(int *n, char *ch);  //�������� �������
void Sotni(int *n, char *ch);  //�������� �����
void Desiatki(int *n, char *ch); //�������� �������
void Desiatki_alternativ(int *n, char *ch); //�������� 10,11,12...19

int _tmain()
{
	SetConsoleCP(1251); 		// �������� ������� �����
	SetConsoleOutputCP(1251); 	//

	int n = 0; //�������� �����
	char ch; //�����
	int sotni = 0, desiatki = 0, edinici = 0; // ���������� ��� �������� �����, �������� � ������ ����� n

	printf("������� � ���������� ����������� ����� n <= 1000\n");
	scanf(" %d", &n);  //���� n
	printf("������� � ���������� ������, ����������� ����� (������� ���������(���������) ������\n");
	scanf(" %c", &ch); //���� ch
	Proverka(&n, &ch); //�������� ������������ ����� ����� � ������
	printf("\n�����: %d, �����: %c(��� ������.)\n", n, ch);
	if(ch == '�')printf("(�) ");

	if(n == 1000) Tysiachi(&n, &ch); //� ������ n = 1000
	else
	{
		edinici = n % 10;  //�������
		n /= 10;
		desiatki = n % 10;  //�������
		n /= 10;
		sotni = n % 10; //�����
	}
	//� ��������� �������:
	if(sotni)
	{
		Sotni(&sotni, &ch);  //������� �����
		printf(" ");
	}
	if(desiatki)
	{
		if(desiatki == 1) //���� 10,11,12...19
        {
			int x = desiatki * 10 + edinici;

			Desiatki_alternativ(&x, &ch); //������� [10,19]
			printf(" ");
		}
		else
		{
			Desiatki(&desiatki, &ch); //������� �������
			printf(" ");
		}
	}
	if(edinici && desiatki != 1)  //���� �� 10,11...19
	{
		Edinici(&edinici, &ch); //������� �������
		printf(" ");
	}
	//������� ��� �������� ���������������:
	if(edinici != 1 || desiatki == 1)
		switch(ch)
		{
			case '�': printf("(�������)\n"); break;
			case '�': printf("(�������)\n"); break;
			case '�': printf("(�������)\n"); break;
			case '�': printf("(�������)\n"); break;
			case '�': printf("(��������)\n"); break;
			case '�': printf("(�������)\n"); break;
		}
	else
		switch(ch)
		{
			case '�': printf("(����)\n"); break;
			case '�': printf("(�����)\n"); break;
			case '�': printf("(�����)\n"); break;
			case '�': printf("(����)\n"); break;
			case '�': printf("(������)\n"); break;
			case '�': printf("(�����)\n"); break;
		}

	system("pause");
	return 0;
}

void Proverka (int *n, char *ch) //�������� ������������ ����� ����� � ������
{
    char paderzi[] = "������";  // ������ ���������� ��� ������
	bool paderz = false; // ���������� ������

	//�������� ������ ch
	for(int i = 0; i < 6; i++)
	{
		if(*ch == paderzi[i])
		{
			paderz = true;   // ��� ������ ����� ���������� �� ������� - break
			break;
		}
	}
	if(!paderz)
	{
		printf("�.�. ��� ����� ������ ���� �������� ������, ���������� ����� ����� � ������������ ������ (�)\n");
		*ch = '�';
	}
	//�������� ����� n
	if(*n <= 0)
	{
		printf("�.�. ��������� ����� �� �������� �����������, ��� ���� ��������� ����������� ��������� �������� (1)\n");
		*n = 1; // �������� ���������� ��������� (1)
	}
	else if(*n > 1000)
	{
		printf("�.�. ��������� ����� n > 1000, ��� ���� ��������� ������������ ��������� �������� (1000)\n");
		*n = 1000; // �������� ����������� ��������� (1000)
	}
}

void Tysiachi(int *n, char *ch)
{
	printf("%d � (%c) ������:\n", *n, *ch);
	switch(*ch)
	{
		case '�': printf("������"); return;
		case '�': printf("������"); return;
		case '�': printf("������"); return;
		case '�': printf("������"); return;
		case '�': printf("�������"); return;
		case '�': printf("������"); return;
	}
}

void Edinici(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case '�': printf("����"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("����"); return;
					case '�': printf("�����"); return;
					case '�': printf("�����"); return;
				}
		case 2: switch(*ch)
				{
					case '�': printf("���"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("���"); return;
					case '�': printf("�����"); return;
					case '�': printf("����"); return;
				}
		case 3: switch(*ch)
				{
					case '�': printf("���"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("���"); return;
					case '�': printf("�����"); return;
					case '�': printf("����"); return;
				}
		case 4: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("�������"); return;
					case '�': printf("�������"); return;
					case '�': printf("������"); return;
					case '�': printf("��������"); return;
					case '�': printf("�������"); return;
				}
		case 5: switch(*ch)
				{
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("�����"); return;
					case '�': printf("����"); return;
				}
		case 6: switch(*ch)
				{
					case '�': printf("�����"); return;
					case '�': printf("�����"); return;
					case '�': printf("�����"); return;
					case '�': printf("�����"); return;
					case '�': printf("������"); return;
					case '�': printf("�����"); return;
				}
		case 7: switch(*ch)
				{
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("����"); return;
					case '�': printf("�����"); return;
					case '�': printf("����"); return;
				}
		case 8: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("��������"); return;
					case '�': printf("������"); return;
				}
		case 9: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("�������"); return;
					case '�': printf("������"); return;
				}
	}
}

void Sotni(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case '�': printf("���"); return;
					case '�': printf("���"); return;
					case '�': printf("���"); return;
					case '�': printf("���"); return;
					case '�': printf("���"); return;
					case '�': printf("���"); return;
				}
		case 2: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
				}
		case 3: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
				}
		case 4: switch(*ch)
				{
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
				}
		default:
		{
			Edinici(n, ch);
			switch(*ch)
				{
					case '�': printf("���"); return;
					case '�': printf("���"); return;
					case '�': printf("����"); return;
					case '�': printf("���"); return;
					case '�': printf("�����"); return;
					case '�': printf("����"); return;
				}
		}
	}
}

void Desiatki(int *n, char *ch)
{
	switch(*n)
	{
		case 1: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("�������"); return;
					case '�': printf("������"); return;
				}
		case 2: switch(*ch)
				{
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("���������"); return;
					case '�': printf("��������"); return;
				}
		case 3: switch(*ch)
				{
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("��������"); return;
					case '�': printf("���������"); return;
					case '�': printf("��������"); return;
				}
		case 4: switch(*ch)
				{
					case '�': printf("�����"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("�����"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
				}
		case 9: switch(*ch)
				{
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
					case '�': printf("���������"); return;
				}
		default:
		{
			Edinici(n, ch);
			switch(*ch)
				{
					case '�': printf("�����"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("�����"); return;
					case '�': printf("�������"); return;
					case '�': printf("������"); return;
				}
		}
	}
}

void Desiatki_alternativ(int *n, char *ch)
{
    switch(*n)
	{
		case 10: switch(*ch)
				{
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("������"); return;
					case '�': printf("�������"); return;
					case '�': printf("������"); return;
				}
		case 11: printf("����"); break;
		case 12: printf("���"); break;
		case 13: printf("���"); break;
		case 14: printf("�����"); break;
		case 15: printf("���"); break;
		case 16: printf("����"); break;
		case 17: printf("���"); break;
		case 18: printf("�����"); break;
		case 19: printf("�����"); break;
	}
    switch(*ch)
	{
		case '�': printf("�������"); return;
		case '�': printf("�������"); return;
		case '�': printf("�������"); return;
		case '�': printf("�������"); return;
		case '�': printf("��������"); return;
		case '�': printf("�������"); return;
	}
}
