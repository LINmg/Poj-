#include<stdio.h>
#define MAXN 200

void Mult(int *p1,int *p2,int *len1, int len2) {
	int i,j,temp[MAXN];
	for (i = 0; i < MAXN;i++)temp[i]=0;
	for (i = 0; i <= len2; i++) {
		for (j = 0; j <= *len1; j++) {
			temp[j + i] += p1[j] * p2[i];
		}
	}
	int k = *len1 + len2 + 2;
	for (i = 0; i < k; i++) {
		if (temp[i] >= 10) {
			temp[i + 1] += temp[i] / 10;
			temp[i] = temp[i] % 10;
		}
	}
	while (temp[k] == 0) k--;
	for(i=0;i<=k;i++)	p1[i] = temp[i];
	*len1 = k;
}

int main() {
	char a[10], d[MAXN];
	int b[MAXN],c[MAXN];
	int n,i,j, count;
	while (scanf("%s%d", a, &n)!=EOF) {
		j = 0;count = 0;
		for (i = 5; i >= 0; i--) {
			if (a[i] == '.')count = 5 - i;
			else  c[j++] = a[i] - '0';
		}
		j--;
		int len_a = 0; b[0] = 1;
		for (i = 0; i < n; i++) {
			Mult(b, c, &len_a, j);
		}
		j = 0;
		while (len_a < count*n - 1) {
			len_a++;
			b[len_a] = 0;
		}
		for (i = len_a; i >= 0; i--) {
			if (i ==  count*n-1)d[j++] = '.';
			d[j++] = b[i] + '0';
		}
		while (d[j - 1] == '0' && count != 0)j--;
		if (d[j - 1] == '.')j--;
		d[j] = '\0';
		printf("%s\n", d);
	}
	return 0;
}