#include <stdio.h>
#define N 2000

int main() {
	int n,i,j=0;
	char In[N],Out[N+1];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c", &In[i]);
	}
	int up = 0, down = n-1;
	bool left=true;
	while (j < n) {
		for (i = 0; i < down-up; i++) {
			if (In[up+i] < In[down-i]) {
				left = true;
				break;
			}
			else if (In[up+i] > In[down-i]) {
				left = false;
				break;
			}
		}
		if (left) Out[j++] = In[up++];
		else Out[j++] = In[down--];
	}
	for (i = 0; i < n; i++) {
		printf("%c", Out[i]);
		if ((i + 1) % 80 == 0 && i < n - 1)printf("\n");
	}
	printf("\n");
	return 0;
}