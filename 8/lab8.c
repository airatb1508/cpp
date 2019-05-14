/* Вариант №2а
 * Условие: //Возможно напишу позже
 */
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAXDL 21

int main() {
	setlocale(LC_ALL, "ru");
	char start[MAXDL];
	char end[MAXDL];
	printf("Введите выражение:\n");
	scanf("%s", start);

	int pr[MAXDL], pos = 0, p = -1, tmp;
	char op[MAXDL], el;
	for(int i = 0; start[i] != '\0' && i < MAXDL; i++){
		tmp = 0;
		el = start[i];
		printf("%c\n", el);
		if('a' <= el && el <= 'z'){
			end[pos] = el;
			pos++;
		}
		else if(el == '+' || el == '-' || el == '*' || el == '/' || el == ' '){
			p++;
			op[p] = el;
			if(el == '+' || el == '-') pr[p] = 1;
			else if (el == ' ') pr[p] = 0;
			else pr[p] = 2;
			printf("op:");
			for(int j = 0; j <= p; j++) printf(" %c", op[j]);
			printf("\npr:");
			for(int j = 0; j <= p; j++) printf(" %d", pr[j]);
			printf("\n");
		}
		while(p > 0 && pr[p] <= pr[p-1]){
			end[pos] = op[p-1];
			pos++;
			op[p-1] = op[p];
			pr[p-1] = pr[p];
			p--;
			tmp++;
		}
		if (tmp != 0 && pr[p] == 0) break;
		printf("op:");
		for(int j = 0; j <= p; j++) printf(" %c", op[j]);
		printf("\npr:");
		for(int j = 0; j <= p; j++) printf(" %d", pr[j]);
		printf("\n");
	}
	
	printf("\nПоследовательность элементарных присваиваний:\n%s\n", end);
	return 0;
}
