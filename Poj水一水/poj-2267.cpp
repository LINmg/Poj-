#include<stdio.h>
#include<string.h>

bool prime1[100001];

void isprime() {
	memset(prime1, true, sizeof(prime1));
	for (int i = 2; i *i <= 100000; i++) {
		if (prime1[i]) {
			for (int j = i * i; j <= 100000; j =j+ i) {
				prime1[j] = false;
			}
		}
	}
}

int main() {
	isprime();
	int n;
	while (scanf("%d",&n)&&n!=0) {
		int i;
		for (i = 3;i<n; i=i+2) {
			if (prime1[i]&&prime1[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
	return 0;
}