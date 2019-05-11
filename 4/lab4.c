/* Вариант №4а
 * вывод студентов с последней оценкой '2'
 */
#include <stdio.h> 
#include <conio.h> 
#include <string.h> 
#define MAX 30 

struct STUDENT
{
	char fio[15]; 
	char oc[7]; 
};
struct EL_TAB
{
	char fio[15];   
	int oc[5]; 
};
 
void PechTab(EL_TAB * tab, int n);
void Stud(EL_TAB * tab, int n);


int main()
{
	FILE *f; 
	STUDENT tz; 
	EL_TAB tab[MAX]; 
	int n; 
	int i;
	fopen_s(&f, "st4.txt", "r");
	if (f == NULL)
	{
		puts("NO st4.txt");
		_getch();
		return 0;
	}
	
	n = 0;
	while (fgets((char *)&tz, sizeof(struct STUDENT), f) != NULL)
	{
		for (i = 0; i < 5; i++)
		{
			int ocenka = tz.oc[i] - '0';
			tab[n].oc[i] = ocenka;
		}
		tz.fio[14] = '\0';
		strcpy_s(tab[n].fio, tz.fio);
		n++;
	}
	fclose(f);
	PechTab(tab, n);
	Stud(tab, n);
	return 0;
	_getch();
} 
void PechTab(EL_TAB * tab, int n)
{
	int j, i;
	puts("\n Studenty ");
	puts("------------------------------");
	for (j = 0; j < n; j++)
	{
		tab[j].fio[14] = '\0';
		printf("%s ", tab[j].fio);
		for (i = 0; i < 5; i++)
			printf(" %i", tab[j].oc[i]);
		printf("\n");
	}
}
void Stud(EL_TAB * tab, int n) 
{
	int j, i, d = 0;
	puts("\n Studenty s poslednei dvojkoi");
	puts("------------------------------");
	for (j = 0; j < n; j++)
	{
		tab[j].fio[14] = '\0';
		if (tab[j].oc[4] == 2)
		{
      d++;
			printf("%s ", tab[j].fio);
			for (i = 0; i != 5; i++)
				printf(" %i", tab[j].oc[i]);
			printf("\n");
		}
	}
  if(d == 0)
    printf("NaN");
	_getch();
}
