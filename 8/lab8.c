/* Вариант №2а
 * Условие: //Возможно напишу позже
 */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAXDL 21

void rPrint(char *toPrint){
  for(int i = 0; i < 3; i++){
    if ('0' <= toPrint[i] && toPrint[i] <= '9') printf(" R%c", toPrint[i]);
    else printf(" %c", toPrint[i]);
  }
  printf("\n");
}

void getAns(char *prim){
  char let[MAXDL]; // стек аперандов
  int letCounter = -1;
  int r = 1;
  for(int i = 0; i < MAXDL && prim[i] != ' ' && prim[i] != '\0'; i++){
    if('a' <= prim[i] && prim[i] <= 'z')
      let[++letCounter] = prim[i];
    else if(prim[i] == '+' || prim[i] == '-' || prim[i] == '*' || prim[i] == '/'){
      printf("R%d =", r);
      char go[3] = {let[letCounter - 1], prim[i], let[letCounter - 0]};
      rPrint(go);
      let[letCounter-- - 1] = r++ + '0';
    }
  }
  return;
}

int main() {
  setlocale(LC_ALL, "ru");
  char prim[MAXDL];
  printf("Введите выражение в постфиксной (обратной польской) записи:\n");
  scanf("%s", prim);
  printf("\nПоследовательность элементарных присваиваний:\n");
  getAns(prim);
	return 0;
}

// abc*+def+/-
// ab*cd/+e-
