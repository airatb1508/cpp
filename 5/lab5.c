/* Вариант №4б
 * записать в массив А все идентификаторы списка начинающиеся с заданной буквы
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXDL 9

char A[MAXDL][MAXDL];

struct el_sp{
	char  id[MAXDL];
	struct el_sp *sled;
};

void vkl(struct el_sp **p, char t_id[]){
	struct el_sp  *pt, *k, *j = NULL;
	pt = malloc(sizeof(struct el_sp));
	strcpy(pt->id, t_id);
	if (*p == NULL || strcmp(pt->id, (*p)->id) < 0){
		pt->sled = *p;
		*p = pt;
	}
	else{
		k = *p;
		while (k != NULL && strcmp(pt->id, k->id) >= 0){
			j = k;
			k = k->sled;
		}
		j->sled = pt;
		pt->sled = k;
	}
}

void pech_sp(struct el_sp *p){
	struct el_sp *i;
	printf("\nРезультат:\n");
	for (i = p; i != NULL; i = i->sled)puts(i->id);
}

int oneLet(struct el_sp *p, char let){
	struct el_sp *i;
	int f = 0;
	for (i = p; i != NULL; i = i->sled){
		if(i->id[0] == let){
			strcpy(A[f], i->id);
			f++;
		}
	}
	return(f);
}

int main(){
	setlocale(LC_ALL, "ru");
	struct el_sp *p;
	p = NULL;
	int k, len, n, f;
	char newId[MAXDL], t_id[MAXDL], let;
	struct el_sp *e;
	printf("\nВведите букву: ");
	scanf("%c", &let);
	getchar();
	printf("\nВведите число идентификаторов\nn = ");
	scanf("%u", &n);
	getchar();
	printf("Введите идентификаторы\n");
	printf("(После каждого нажимайте <Enter> )\n");
	for (int i = 0; i < n; i++){
		scanf("%s", t_id);
		vkl(&p, t_id);
	}
	pech_sp(p);
	f = oneLet(p, let);
	printf("\nМассив A:\n");
	if(f) for(int y = 0; y<f; y++) printf("%s\n", A[y]);
	else printf("Пустой\n");
	return 0;
}
