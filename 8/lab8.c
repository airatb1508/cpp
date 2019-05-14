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

	int pr[MAXDL], pos = 0, p = -1;
	char op[MAXDL], el;
	for(int i = 0; start[i] && start[i] != '\0' && i < MAXDL; i++){
		el = start[i];
		printf("%c\n", el);
		if('a' <= el && el <= 'z'){
			end[pos] = el;
			pos++;
		}
		else if(el == '+' || el == '-' || el == '*' || el == '/'){
			p++;
			op[p] = el;
			if(el == '+' || el == '-') pr[p] = 1;
			else pr[p] = 2;
	
		}
		while(p > 0 && pr[p] <= pr[p-1]){
			end[pos] = op[p-1];
			pos++;
			op[p-1] = op[p];
			pr[p-1] = pr[p];
			p--;
		}
	}
	
	printf("\nПоследовательность элементарных присваиваний:\n%s\n", end);
	return 0;
}
