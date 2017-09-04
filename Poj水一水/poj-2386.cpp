#include <stdio.h>
#define MAX 100
int M, N;
char a[MAX][MAX];

void dfs(int x,int y) {
	a[x][y] = '.';
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + i >= 0 && x + i < N&&y + j >= 0 && y + j < M&& a[x + i][y + j] == 'W') dfs(x + i, y + j);
		}
	}
}

int main() {
	int i,j,k=0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", a[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (a[i][j] == 'W') {
				dfs(i, j);
				k++;
			}
		}
	}
	printf("%d\n", k);
	return 0;
}