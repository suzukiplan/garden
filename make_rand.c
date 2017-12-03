#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int table[1024];
	int i, j;
	srand((unsigned int)time(NULL));
	printf("int rand_table[] = {\n");
	for (i = 0; i < 1024; i++) table[i] = -1;
	for (i = 0; i < 1024; i++) {
		int p = rand() % 1024;
		if (-1 != table[p]) {
			i--;
			continue;
		}
		table[p] = i;
	}
	for (i = 0; i < 1024 / 32; i++) {
		printf("    ");
		for (j = 0; j < 32; j++) {
			if (j) printf(", ");
			printf("%d", table[i * 32 + j]);
		}
		printf("\n");
	}
	printf("};\n");
	return 0;
}