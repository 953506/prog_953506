#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int idArtist = 0;
int idCompos = 0;
int money=0;
int valuePay=0;
int value=0;
int valueArtists;
bool flag = false;
FILE* fin;
FILE* fout;

struct Composition
{
	char* Name;
	char* artistName;
	char* text;
	char* bitrate;
	float size;
	int id;
	char* albomName;
	unsigned int yearOut;
	int Prise;
	Composition* next;
	char* art;
};

struct Artist
{
	char* Name;
	int id;
	char* albom;
	Composition* compositions;
	char* simpleInfo;
	int yearBirth;
	Artist* left;
	Artist* right;
};

void ReadFromFile(Artist** root, FILE* fp);
void menu();
void AddComp(Composition** node, Composition* comp);
void AddArtist(Artist** node, Artist* value);
void Show(Artist* node);
void ShowComp(Composition* comp);
void WriteToFile(Artist* root, FILE* fp);
void WriteToFile(Composition* st, FILE* fp);
char* GetString(int size);
Composition* Search(Artist* node, char* name);
Composition* Search(Composition* st, char* name);
bool Cmp(char* s1, char* s2);
void Pay(Composition** track_basket);
void Report();

int main()
{
	
	char ch;
	int idArtist = 0;
	int idCompos = 0;
	char* name;
	Artist* artistHead= NULL;
	Composition* track_basket = NULL;

	do
	{
		menu();
		scanf("%s", &ch);
		fflush(stdin);
		switch (ch)
		{
		case '1':
			fin = fopen("Artist.txt", "r");
			ReadFromFile(&artistHead, fin);
			fclose(fin);
			break;

		case '2':
			fout = fopen("file.txt", "w");
			WriteToFile(artistHead, fout);
			fclose(fout);
			break;

		case '3':
			Show(artistHead);
			break;

		case '4':
			system("cls");
			Pay(&track_basket);
			break;

		case '5':
			Report();
			break;

		case '6':
			printf("Enter the name of the song that's just want to add\n");
			name = GetString(128);
			name[strlen(name) - 1] = '\n';

			Composition* track = Search(artistHead, name);
			if (track != NULL)
			{
				track->next = NULL;
				AddComp(&track_basket, track);
			}
			else
				printf("eror");
			fflush(stdin);
			break;
		}

	} while (ch != 'q');
	return 0;
}

void menu()
{
	puts("1 - Read from file");
	puts("2 - Write to file");
	puts("3 - Show tracks");
	puts("4 - Pay");
	puts("5 - Report");
	puts("6 - Add track in busket");
	puts("q - Quit");
}

void ReadFromFile(Artist** root, FILE* fp) {
	while (!feof(fp))
	{
		Artist* ar = (Artist*)malloc(sizeof(Artist));
		char* buffer = (char*)malloc(40 * sizeof(char));
		ar->Name = (char*)malloc(20 * sizeof(char));
		ar->compositions = NULL;
		ar->simpleInfo = (char*)malloc(300 * sizeof(char));
		ar->albom = (char*)malloc(40 * sizeof(char));
		fgets(ar->Name, 40, fp);
		fgets(ar->albom, 30, fp);
		fgets(ar->simpleInfo, 300, fp);
		fscanf(fp, "%d", &ar->yearBirth);
		fgets(buffer, 2, fp);
		fgets(buffer, 40, fp);

		ar->id = idArtist++;
		
		while (buffer[0]!='\n')
		{
			Composition* comp = (Composition*)malloc(sizeof(Composition));
			comp->Name = (char*)malloc(40 * sizeof(char));
			comp->text = (char*)malloc(300 * sizeof(char));
			comp->bitrate = (char*)malloc(10 * sizeof(char));
			comp->albomName = (char*)malloc(40 * sizeof(char));
			comp->art = (char*)malloc(40 * sizeof(char));
			comp->Name = _strdup(buffer);
			comp->artistName = (char*)malloc(40 * sizeof(char));
			comp->artistName = ar->Name;
			fgets(comp->text, 300, fp);
			fgets(comp->bitrate, 10, fp);
			fscanf(fp, "%f", &comp->size);
			fgets(buffer, 2, fp);
			fgets(comp->albomName, 40, fp);
			fscanf(fp, "%d", &comp->yearOut);
			fscanf(fp, "%d", &comp->Prise);
			fgets(buffer, 2, fp);
			fgets(comp->art, 20, fp);
			comp->id = idCompos++;
			AddComp(&ar->compositions, comp);
			fgets(buffer, 40, fp);
		}
		AddArtist(root, ar);
	}
}

void AddComp(Composition** st, Composition* comp)
{
	comp->next = *st;
	*st = comp;
	value++;
}

void AddArtist(Artist** node, Artist* ar)
{
	if (*node == NULL) {
		ar->left = NULL;
		ar->right = NULL;
		*node = ar;
	}
	else if (ar->id>= (*node)->id) {
		if ((*node)->right != NULL)
			AddArtist(&(*node)->right, ar);
		else
		{
			ar->left = NULL;
			ar->right = NULL;
			(*node)->right = ar;
		}
	}
	else {
		if ((*node)->left != NULL)
			AddArtist(&(*node)->right, ar);
		else {
			ar->left = NULL;
			ar->right = NULL;
			(*node)->left = ar;
		}
	}
	valueArtists++;
}

void Show(Artist* node)
{
	if (node == NULL)
	{
		return;
	}
	Show(node->left);
	printf("Name: %s", node->Name);
	printf("Alboms: %s", node->albom);
	printf("Info: %s", node->Name);
	printf("Year of Birdth: %d\n", node->yearBirth);
	printf("Composition:\n");
	ShowComp(node->compositions);
	Show(node->right);
}

void ShowComp(Composition* comp)
{
	if (comp == NULL)
	{
		return;
	}
	printf("Tracks name: %s", comp->Name);
	printf("Artist Name: %s", comp->artistName);
	printf("Text:\n%s", comp->text);
	printf("Bitrate: %s", comp->bitrate);
	printf("Size: %f MB\n", comp->size);
	printf("Albom: %s", comp->albomName);
	printf("Prise: %d $\n", comp->Prise);
	printf("Art: %s\n", comp->art);
	ShowComp(comp->next);
}

void WriteToFile(Artist* root, FILE* fp)
{
	if (root == NULL)
		return;
	WriteToFile(root->left, fp);
	
	if(flag)
		fprintf(fp, "%c",'\n');
	fprintf(fp, "%s%s%s%d\n", root->Name, root->albom, root->simpleInfo, root->yearBirth);
	flag = true;
	WriteToFile(root->compositions, fp);
	
	WriteToFile(root->right, fp);
}

void WriteToFile(Composition* st, FILE* fp)
{
	if (st == NULL)
		return;
	WriteToFile(st->next, fp);
	fprintf(fp, "%s%s%s%f\n%s%d\n%d\n%s", st->Name, st->text, st->bitrate, st->size, st->albomName, st->yearOut, st->Prise, st->art);
}

char* GetString(int size)
{
	char buffer[128];
	int i = 0;
	char c;
	if ((size > 128) || (size <= 0))
		size = 128;
	while (--size > 0)
	{
		c = getchar();
		if (c == '\n')
			size = 0;
		else
		{
			buffer[i++] = c;
		}
	}
	buffer[i] = ' ';
	buffer[i + 1] = '\0';
	return _strdup(buffer);
}

Composition* Search(Artist* node, char* name)
{
	if (node == NULL)
		return NULL;
	if (Search(node->compositions, name) != NULL)
		return Search(node->compositions, name);
	if (Search(node->left, name) != NULL)
		return Search(node->left, name);
	return Search(node->right, name);
}

Composition* Search(Composition* node, char* name)
{
	if (node == NULL)
		return NULL;
	if (Cmp(node->Name, name))
		return node;
	return Search(node->next, name);
}

bool Cmp(char* s1, char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (strlen(s1) != strlen(s2))
		return false;
	for (int i = 0, len = strlen(s1); i < len; i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}

void Pay(Composition** track_basket)
{
	printf("requisites:\nBY95AKBB30140003064183010000");
	if (*track_basket != NULL)
	{
		valuePay++;
		money += (**track_basket).Prise;
		Composition* p = *track_basket;
		*track_basket = (**track_basket).next;
		free(p);
	}
}

void Report()
{
	printf("\nvalue atists: %d", valueArtists);
	printf("\nvalue tracks: %d", value);
	printf("\nvalue sold tracks: %d", valuePay);
	printf("\nMoney: %d\n", money);
}