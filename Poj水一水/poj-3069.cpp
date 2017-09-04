#include <stdio.h>
#include <algorithm>
#define Max 1000
using namespace std;
int r, n, x[Max];

int main() {
	int i;
	while (scanf("%d %d", &r, &n) && r != -1) {
		int j = 0, ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}
		sort(x, x + n);
		while (j < n) {
			int s = x[j++];
			while (j < n&&x[j] <= s + r)j++;
			int p = x[j - 1];
			while (j < n&&x[j] <= p + r) {
				j++;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}