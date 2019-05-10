#include <stdio.h>

#define NMAX 7

int  g[NMAX][NMAX], n;

void inputGrapg(int n){
	int  i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = 0;
	puts("Введите последовательность ребер, завершив ввод ");
	puts("нажатием Ctrl - Z");
	while (fscanf(stdin, "%d %d", &i, &j) != EOF)
		if (i < n && j < n) g[i][j] = g[j][i] = 1;
	printf("\n");
	return;
}

void checkAllSm() {
	int r, s=0;
	printf("Вершины смежные со всеми другими вершинами:\n");
	for (int i = 0; i < n; i++) {
		r = 0;
		for (int j = 0; j < n; j++) {
			if (i!=j && g[i][j] == 1) {
				r++;
			}
		}
		if (r == n - 1) {
			printf("%d \n", i);
			s++;
		}
	}
	if (s == 0) {
		printf("Таких нет\n");
	}
	return;
}

int main(){
	int i, j, l;
	printf("\nВведите количество вершин: ");
	scanf("%d", &n);
	if (n > 1)
		inputGrapg(n);
	checkAllSm();
  return 0;
}
