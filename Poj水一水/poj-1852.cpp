#include <stdio.h>
#define __max(a,b) (((a) > (b)) ? (a) : (b))
#define __min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int l,m,n;
	scanf("%d", &n);
	while (n-- != 0) {
		scanf("%d %d", &l, &m);
		int i,a,max=0,min=0;
		for (i = 0; i < m; i++) {
			scanf("%d", &a);
			min = __max(min, __min(a ,l - a));
			max = __max(max, __max(a, l - a));
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}