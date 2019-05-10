#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define MAX 30

struct STUDENT {
	char fio[15];
	char oc[7];
};
struct EL_TAB {
	char fio[15];
	int oc[5];
	float srball;
};

void PechTab(struct EL_TAB * tab, int n);
void Stud(struct EL_TAB * tab, int n);

int main() {
	setlocale(LC_ALL, "ru");
	FILE *f;
	struct STUDENT tz;
	struct EL_TAB tab[MAX];
	int n = 0, i;
	float s;
	fopen_s(&f, "st.txt", "r");
	if (f == NULL) {
		puts("File not found");
		return 1;
	}
	while (fgets((char *)&tz, sizeof(struct STUDENT), f) != NULL) {
		for (i = 0, s = 0; i < 5; i++) {
			int ocenka = tz.oc[i] - '0';
			tab[n].oc[i] = ocenka;
			s += ocenka;
		}
		tz.fio[14] = '\0';
		strcpy_s(tab[n].fio, 15, tz.fio);
		tab[n++].srball = s / 5;
	}
	fclose(f);
	PechTab(tab, n);
	puts("\n");
	puts("Students with sr.ball < 4.0");
	Stud(tab, n);
	_getch();
	return 0;
}

void PechTab(struct EL_TAB * tab, int n) {
	int j;
	puts("\nName        Sr.ball");
	puts("-----------------------");
	for (j = 0; j < n; j++) {
		printf("%s  %.1f\n", tab[j].fio, tab[j].srball);
	}
}

void Stud(struct EL_TAB * tab, int n) {
	int k = 0;
	puts("Name       Mark      Sr.ball");
	puts("-----------------------------------");
	for (int j = 0; j < n; j++) {
		if (tab[j].srball < 4.0) {
			printf("%s \t", tab[j].fio);
			for (int i = 0; i < 5; i++)
				printf("%d ", tab[j].oc[i]);
			printf("  %.1f\n", tab[j].srball);
			k++;
		}
	}
	if (k == 0)
		printf("empty set\n");
	return;
}