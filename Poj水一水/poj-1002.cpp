#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 50
#define Maxn 1000
char s[] = "ABCDEFGHIJKLMNOPRSTUVWXY9876543210";
void Change(char *a1, char*a2) {
	int i = 0;
	while (a2[i] != '\0') {
		a1[i] = a2[i];
		i++;
	}
	a1[i] = '\0';
}
void Dic(char(*a)[N],int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i-1; j++) {
			if (strcmp(a[j], a[j + 1]) > 0) {
				char b[N];
				Change(b, a[j]);
				Change(a[j], a[j+1]);
				Change(a[j+1], b);
			}
		}
	}
}
int main() {
	int n,i,j,k,m,o,d[Maxn];
	char a[N],b[N],temp[N],c[Maxn][N],Out[Maxn][N];
	scanf("%d", &n);
	m = 0;
	for (i = 0; i < Maxn; i++)d[i] = 0;
	while (n-- != 0) {
		k = 0;
		scanf("%s", a);
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] != '-') {
				for ( j = 0; j < 34; j++) {
					if (s[j] == a[i]) break;
				}
				if (j < 24) b[k++] = s[31 - (j / 3)];
				else b[k++] = s[j]; 
			}
			if (k == 3) b[k++] = '-';
		}
		b[k] = '\0';
		for (i = 0; i < m; i++) {
			if (strcmp(c[i], b) == 0) {
				d[i]++;
				break;
			}
		}
		if (i == m) {
			for (j = 0; j <= k; j++) {
				c[m][j] = b[j];
			}
			d[m++]++;
		}
	}
	k = 0;
	for (i = 0; i < m; i++) {
		j = 0;
		if (d[i] > 1) {
			while (c[i][j] != '\0') {
				Out[k][j] = c[i][j];
				j++;
			}
			Out[k][j++] = ' ';
			_itoa(d[i], temp, 10);
			for (o = 0; temp[o] != '\0'; o++)
				Out[k][j++] = temp[o];
			Out[k][j] = '\0';
			k++;
		}
	}
	if (k == 0) printf("No duplicates.\n");
	else {
		Dic(Out, k);
		for (i = 0; i < k; i++)
			printf("%s\n", Out[i]);
	}
	return 0;	
}