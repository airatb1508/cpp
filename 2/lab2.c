/* Вариант №2: strcmp */
#include <string.h>
#include <stdio.h>

int main() {
	char str1[81], str2[81];
	int r = 0;
	gets(str1);
	gets(str2);
	r = strcmp(str1, str2);
	printf("r = %d", r);
	return 0;
}
