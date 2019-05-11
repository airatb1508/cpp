/* Вариант №1е
 * удалить k первых элементов
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXDL 9

struct el_sp {
	char  id[MAXDL];
	struct el_sp *sled;
};

void  vkl(struct el_sp **p, char t_id[]) {
	struct el_sp  *pt, *k, *j = NULL;
	pt = malloc(sizeof(struct el_sp));
	strcpy(pt->id, t_id);
	if (*p == NULL || strcmp(pt->id, (*p)->id) < 0) {
		pt->sled = *p;
		*p = pt;
	}
	else {
		k = *p;
		while (k != NULL && strcmp(pt->id, k->id) >= 0) {
			j = k;
			k = k->sled;
		}
		j->sled = pt;
		pt->sled = k;
	}
}

void pech_sp(struct el_sp *p) {
	if (p == NULL)
		printf("Список пуст\n");
	else {
		struct el_sp *i;
		for (i = p; i != NULL; i = i->sled)
			printf("%s\n", i->id);
	}
}

void delKEl(struct el_sp **p, unsigned k) {
	struct el_sp *i;
	int n = 0;
	for(i = *p; n < k && i != NULL; i = *p, n++){
		*p = i->sled;
		free(i);
	}
}

int main() {
	struct el_sp  *p;
	unsigned n, k;
	char t_id[MAXDL];
	setlocale(LC_ALL, "ru");

	printf("\nВведите количество элементов: ");
	scanf("%u", &n);
	p = NULL;
	printf("\nВведите идентификаторы\n");
	printf("(После каждого нажимайте <Enter> )\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", t_id);
		vkl(&p, t_id);
	}
	printf("\nСписок:\n");
	pech_sp(p);
	printf("\nВведите сколько элементов нужно удалить: ");
	scanf("%u", &k);
	delKEl(&p, k);
	printf("\nСписок после удаления %u первых\n", k);
	pech_sp(p);	
	return 0;
}
