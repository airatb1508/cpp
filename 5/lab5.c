#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXDL 9

struct el_sp{
  char  id[MAXDL];
  struct el_sp *sled;
};

void vkl(struct el_sp **p, char t_id[]){
  struct el_sp  *pt, *k, *j = NULL;
  pt = malloc(sizeof(struct el_sp));
  strcpy(pt->id, t_id);
  if (*p == NULL || strcmp(pt->id, (*p)->id) < 0){
    pt->sled = *p;*p = pt;
  }
  else{
    k = *p;
    while (k != NULL && strcmp(pt->id, k->id) >= 0){
      j = k;
      k = k->sled;
    }j->sled = pt;
    pt->sled = k;
  }
}

void pech_sp(struct el_sp *p){
  struct el_sp *i;
  printf("\nРезультат:\n");
  for (i = p; i != NULL; i = i->sled)puts(i->id);
}

int main(){
  setlocale(LC_ALL, "ru");
  struct el_sp  *p;
  unsigned n;
  unsigned i;
  int k;
  char newId[MAXDL];
  char t_id[MAXDL];
  struct el_sp *e;
  int len;
  printf("\nВведите число идентификаторов\nn = ");
  scanf("%u", &n);
  getchar();
  p = NULL;
  printf("Введите идентификаторы\n");
  printf("(После каждого нажимайте <Enter> )\n\n");
  for (i = 0; i < n; i++){
    gets(t_id);
    if(strcmp(t_id[0], let) == 0) vkl(&p, t_id);
  }
  pech_sp(p);
  printf("\nВведите номер элемента, id которого вы хоите изменить\nk = ");
  scanf("%d", &k);
  pech_sp(p);
  printf("\n\nНажмите на любую кнопку для завершения\n");
}
