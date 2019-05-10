#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		printf("Ñïèñîê ïóñò\n");
	else {
		struct el_sp *i;
		printf("Ñïèñîê:\n");
		for (i = p; i != NULL; i = i->sled)
			printf("%s\n", i->id);
	}
}

void delLastEl(struct el_sp **p) {
	struct el_sp *i, *last = NULL, *pre = NULL;
	for (i = *p; i != NULL; pre = last, last = i, i = i->sled);
	if (*p != last) {
		pre->sled = NULL;
		free(last);
	}
	else {
		free(*p);
		*p = NULL;
	}
}

int main() {
	struct el_sp  *p;
	unsigned n;
	unsigned i;
	char t_id[MAXDL];

	printf("\nВведите количество элементов\nn = ");
	scanf("%u", &n);
	p = NULL;
	printf("Введите идентификаторы\n");
	printf("(После каждого нажимайте <Enter> )\n\n");
	for (i = 0; i < n; i++) {
		scanf("%s", t_id);
		vkl(&p, t_id);
	}
	pech_sp(p);
	delLastEl(&p);
	printf("\nСписок после удаления последнего элемента\n");
	pech_sp(p);
  return 0;
}
